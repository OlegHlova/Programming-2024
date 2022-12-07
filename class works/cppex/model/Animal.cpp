#include <cstdio>
#include "Animal.h"

Animal::Animal(char *name, double price) {
    _name = name;
    _price = price;
}

Animal::~Animal() {
    delete _name;
    delete &_price;
}

char *Animal::getName() {
    return this->_name;
}

double Animal::getPrice() const {
    return this->_price;
}

void Animal::setName(char *name) {
    // Check if name is not null and is not empty/the same
    if (name != nullptr && name != this->_name) {
        delete this->_name;
        this->_name = name;
    }
}

void Animal::setPrice(double price) {
    // Check if price is not the same
    if (price != this->_price) {
        this->_price = price;
    }
}

Animal::Animal() {
    _name = "A horse with no name";
    _price = 0;
}

char *Animal::toString() {
    char* result = new char[100];
    sprintf(result, "Name: %s, Price: %f", this->_name, this->_price);
    return result;
}


