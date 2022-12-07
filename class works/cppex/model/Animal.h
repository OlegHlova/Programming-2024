

class Animal {
private:
    char* _name;
    double _price;

public:
    Animal(char* name, double price);
    Animal();
    ~Animal();
    char* getName();
    double getPrice() const;
    void setName(char* name);
    void setPrice(double price);
    char* toString();
};

