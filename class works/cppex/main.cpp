#include <iostream>
#include <cstring>
#include "model/Animal.h"
int main() {
    // Create array of 10 Animal objects (malloc)
    auto* animals = new Animal[10];
    animals[0] = *new Animal("Horse", 10);
    animals[1] = *new Animal("Dog", 200);
    animals[2]= *new Animal("Cat", 30);
    animals[3]= *new Animal("Cow", 40);
    animals[4]= *new Animal("Chicken", 5000);
    animals[5]= *new Animal("Pig", 6);
    animals[6]= *new Animal("Sheep", 7);
    animals[7]= *new Animal("Goat", 12);
    animals[8]= *new Animal("Hampster", 15);
    animals[9] = *new Animal("Rabbit", 51);

    // Print animals which price is 10 <= price <= 50
    for (int i = 0; i < 10; i++) {
        if (animals[i].getPrice() >= 10 && animals[i].getPrice() <= 50) {
            std::cout << animals[i].toString() << std::endl;
        }
    }

    // Sort animals by name
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (strcmp(animals[i].getName(), animals[j].getName()) > 0) {
                auto temp = animals[i];
                animals[i] = animals[j];
                animals[j] = temp;
            }
        }
    }

    // Increase hamster price by 10%
    for (int i = 0; i < 10; i++) {
        if (strcmp(animals[i].getName(), "Hampster") == 0) {
            animals[i].setPrice(animals[i].getPrice() * 1.1);
        }
    }

    // Print animals
    for (int i = 0; i < 10; i++) {
        std::cout << animals[i].toString() << std::endl;
    }

}
