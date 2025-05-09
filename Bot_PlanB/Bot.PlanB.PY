import asyncio
import random
from aiogram import Bot, Dispatcher, types, F
from aiogram.filters import Command
from aiogram.types import InlineKeyboardButton, InlineKeyboardMarkup
from aiogram.client.default import DefaultBotProperties


TOKEN = '8039911697:AAFjRB6NZM6zqBeuTBAclOyTELwZGMTp11k'

bot = Bot(token=TOKEN, default=DefaultBotProperties(parse_mode="HTML"))
dp = Dispatcher()
ideas = [
    {"text": "Відкрити мобільний додаток для обміну книгами", "category": "Освіта", "trend": True},
    {"text": "Виробництво еко-пакування для ресторанів", "category": "Еко-бізнес", "trend": True},
    {"text": "Фудтрак зі здоровою їжею", "category": "Їжа", "trend": False},
    {"text": "Онлайн-магазин кастомної моди", "category": "Мода", "trend": True},
    {"text": "Оренда smart-нерухомості", "category": "Нерухомість", "trend": False},
    {"text": "Платформа мікро-курсів для професійної освіти", "category": "Освіта", "trend": True},
]

user_profiles = {}  # user_id: {settings, saved_ideas}
suggested_ideas = []  # для запропонованих ідей користувачами

def main_menu():
    keyboard = InlineKeyboardMarkup(inline_keyboard=[
        [InlineKeyboardButton(text="🔍 Знайти ідею", callback_data="find_idea")],
        [InlineKeyboardButton(text="🧠 Запропонувати ідею", callback_data="suggest_idea")],
        [InlineKeyboardButton(text="📊 Трендові ідеї", callback_data="trending_ideas")],
        [InlineKeyboardButton(text="⚙️ Налаштування", callback_data="settings")]
    ])
    return keyboard

def category_menu():
    keyboard = InlineKeyboardMarkup(inline_keyboard=[
        [InlineKeyboardButton(text="📱 Технології", callback_data="category_Технології")],
        [InlineKeyboardButton(text="🌿 Еко-бізнес", callback_data="category_Еко-бізнес")],
        [InlineKeyboardButton(text="🍔 Їжа", callback_data="category_Їжа")],
        [InlineKeyboardButton(text="👕 Мода", callback_data="category_Мода")],
        [InlineKeyboardButton(text="🏠 Нерухомість", callback_data="category_Нерухомість")],
        [InlineKeyboardButton(text="📚 Освіта", callback_data="category_Освіта")]
    ])
    return keyboard

def save_idea_button():
    keyboard = InlineKeyboardMarkup(inline_keyboard=[
        [InlineKeyboardButton(text="💾 Зберегти ідею", callback_data="save_idea")]
    ])
    return keyboard

@dp.message(Command("start"))
async def cmd_start(message: types.Message):
    user_profiles.setdefault(message.from_user.id, {"saved_ideas": [], "settings": {"format": "short"}})
    await message.answer("Привіт! Я Бот, який щодня генерує креативні бізнес-ідеї 💼\nОбери дію нижче, щоб почати ⬇️", reply_markup=main_menu())

@dp.message(Command("idea"))
async def cmd_idea(message: types.Message):
    idea = random.choice(ideas)
    user_profiles[message.from_user.id]["last_idea"] = idea
    await message.answer(f"Ідея: {idea['text']}", reply_markup=save_idea_button())

@dp.message(Command("category"))
async def cmd_category(message: types.Message):
    await message.answer("Оберіть категорію:", reply_markup=category_menu())

@dp.message(Command("trending"))
async def cmd_trending(message: types.Message):
    trending = [i for i in ideas if i["trend"]]
    text = "\n".join([f"{idx+1}. {i['text']}" for idx, i in enumerate(trending)])
    await message.answer(f"Трендові ідеї:\n{text}")

@dp.message(Command("saveidea"))
async def cmd_saveidea(message: types.Message):
    idea = user_profiles.get(message.from_user.id, {}).get("last_idea")
    if idea:
        user_profiles[message.from_user.id]["saved_ideas"].append(idea)
        await message.answer("Ідею збережено ✅")
    else:
        await message.answer("Немає ідеї для збереження ❌")

@dp.message(Command("myideas"))
async def cmd_myideas(message: types.Message):
    saved = user_profiles.get(message.from_user.id, {}).get("saved_ideas", [])
    if saved:
        text = "\n".join([f"- {i['text']}" for i in saved])
        await message.answer(f"Ваші збережені ідеї:\n{text}")
    else:
        await message.answer("У вас ще немає збережених ідей.")

@dp.message(Command("settings"))
async def cmd_settings(message: types.Message):
    await message.answer("Налаштування ще в розробці 🛠")

@dp.message(Command("suggestidea"))
async def cmd_suggestidea(message: types.Message):
    await message.answer("Напишіть свою ідею у відповідь на це повідомлення.")

@dp.message(F.reply_to_message)
async def handle_reply(message: types.Message):
    if message.reply_to_message and "Напишіть свою ідею" in message.reply_to_message.text:
        suggested_ideas.append({"user": message.from_user.id, "text": message.text})
        await message.answer("Дякуємо! Ваша ідея надіслана на модерацію ✅")

@dp.callback_query()
async def callback_handler(callback: types.CallbackQuery):
    data = callback.data
    user_id = callback.from_user.id

    if data == "find_idea":
        idea = random.choice(ideas)
        user_profiles[user_id]["last_idea"] = idea
        await callback.message.answer(f"Ідея: {idea['text']}", reply_markup=save_idea_button())

    elif data == "save_idea":
        idea = user_profiles.get(user_id, {}).get("last_idea")
        if idea:
            user_profiles[user_id]["saved_ideas"].append(idea)
            await callback.message.answer("Ідею збережено ✅")
        else:
            await callback.message.answer("Немає ідеї для збереження ❌")

    elif data == "trending_ideas":
        trending = [i for i in ideas if i["trend"]]
        text = "\n".join([f"{idx+1}. {i['text']}" for idx, i in enumerate(trending)])
        await callback.message.answer(f"Трендові ідеї:\n{text}")

    elif data == "suggest_idea":
        await callback.message.answer("Напишіть свою ідею у відповідь на це повідомлення.")

    elif data == "settings":
        await callback.message.answer("Налаштування ще в розробці 🛠")

    elif data.startswith("category_"):
        category = data.split("_")[1]
        filtered = [i for i in ideas if i["category"] == category]
        if filtered:
            idea = random.choice(filtered)
            await callback.message.answer(f"Ідея в категорії {category}: {idea['text']}")
        else:
            await callback.message.answer("Немає ідей у цій категорії.")

    await callback.answer()

async def main():
    await dp.start_polling(bot)

if __name__ == "__main__":
    try:
        asyncio.run(main())
    except (KeyboardInterrupt, SystemExit):
        print("Бот зупинено")
