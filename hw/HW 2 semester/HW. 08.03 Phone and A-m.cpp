#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Phone {
public:
    Phone(const string& name, const string& company, double price)
        : Name_(name), Company_(company), Price_(price) {}

    virtual void printInfo() const = 0; 

protected:
    string Name_;
    string Company_;
    double Price_;
};
class MobilePhone : public Phone {
public:
    MobilePhone(const string& name, const string& company, double price,
        const string& color, int memory)
        : Phone(name, company, price), Color_(color), Memory_(memory) {}

    virtual void printInfo() const override {
        cout << "Mobile Phone:\n"
            << "Name: " << Name_ << endl
            << "Company: " << Company_ << endl
            << "Price: " << Price_ << endl
            << "Color: " << Color_ << endl
            << "Memory: " << Memory_ << " GB" << endl;
    }
private:
    string Color_;
    int Memory_;
};
class RadioPhone : public Phone {
public:
    RadioPhone(const string& Name, const string& Company, double Price,
        double Range, bool Answering_machine)
        : Phone(Name,  Company, Price), Range_(Range),
        answering_machine_(Answering_machine) {}

    virtual void printInfo() const override {
        cout << "Radio Phone:\n"
            << "Name: " << Name_ << endl
            << "Company: " << Company_ << endl
            << "Price: " << Price_ << endl
            << "Range: " << Range_ << " km" << endl
            << "Answering machine: " << (answering_machine_ ? "Yes" : "No") << endl;
    }
private:
    double Range_;
    bool answering_machine_;
};
int main() {}

void deletePhones(vector<Phone*>& phones) {
    for (Phone* phone : phones) {
        delete phone;
    }
    phones.clear();
}

vector<Phone*> readPhonesFromFile(const string& fileName) {
    vector<Phone*> phones;
    ifstream file(fileName);
    if (file.is_open()) {
        string type;
        while (file >> type) {
            if (type == "MobilePhone") {
                string name, company, color;
                double price;
                int memory;
                file >> name >> company >> price >> color >> memory;
                phones.push_back(new MobilePhone(name, company, price, color, memory));
            }
            else if (type == "RadioPhone") {
                string name, company;
                double price, range;
                bool answering_machine;
                file >> name >> company >> price >> range >> answering_machine;
                phones.push_back(new RadioPhone(name, company, price, range, answering_machine));
            }
        }
    }
}

void readPhonesFromFile(const string& filename, vector<Phone*>& phones) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return;

        file.close();
    }
}
