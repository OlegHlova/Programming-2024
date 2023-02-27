#include <iostream>

using namespace std;
// Exercise with class ("Client")

class Client {
private:
    string name;
    string address;
    string gmail;
    int number;
public:
    Client() : name(" "), address(" "), gmail(""), number(0) {}
    Client(string name, string address, string gmail , int number) : name(name), address(address), gmail(gmail), number(number) {}
    Client(const Client& p) : name(p.name), address(p.address), gmail(p.gmail), number(p.number) {}

    friend istream& operator>>(istream& is, Client& client) {
        cout << "Enter name-alias:" << endl;
        is >> client.name;
        cout << "Enter address:" << endl;
        is >> client.address;
        cout << "Enter number:" << endl;
        is >> client.number;
        cout << "Enter gmail." << endl;
        is >> client.gmail;

        return is;
    }
    friend ostream& operator<<(ostream& os, Client& client) {
        os << "Name: " << client.name << endl << "Address: " << client.address << endl << "Gmail" <<client.gmail << endl
            << "Number: " << client.number << endl;

        return os;
    }
    string getName() {
        return name;
    }
    string getAddress() {
        return address;
    }
    string getGmail() {
        return gmail;

    }
    int getNumber() {
        return number;
    }
};
class Card {
private:
    Client clients;

    double balance;

    int NumberOfBalance;

public:
    Card() :clients(), balance(0), NumberOfBalance(0) {}

    Card(Client client, double balance, int numOfBal) : clients(client), balance(balance), NumberOfBalance(numOfBal) {}

    double getNumberOfBalance() {
        return NumberOfBalance;
    }
    double getBalance() {
        return balance;
    }
    void addMoney(double money) {
        balance += money;
    }
    void removeMoney(double money) {
        if (balance < money) {
            cout << "Not enough money :( " << endl;
        }
        else {
            balance -= money;
        }
    }

    bool checkFilter(int option, string text) {
        if (option == 0) {
            if (clients.getName() == text) {
                return true;
            }
        }
        else if (option == 1) {
            if (clients.getAddress() == text) {
                return true;
            }
        }
        else if (option == 2) {
            if (clients.getGmail() == text) {
                return true;

            }
               
        }
            
        return false;
    }

    friend ostream& operator<<(ostream& os, Card& card) {
        os << "Client" << endl << "Name: " << card.clients.getName() << endl << "Address: " << card.clients.getAddress() <<endl <<"Gmail"<< card.clients.getGmail()<<
            endl << "Phone number: " << card.clients.getNumber() << endl << "Card number: " << card.getNumberOfBalance() << endl
            << "Balance: " << card.getBalance() << '$' << endl;

        return os;
    }
};

// Information ..
int main() {
    
    Card* Bank = new Card[10];
    Client c1("Andrew" ,"andrew.gmail.com" ,"Shevchenka 16", 4444);
    Client c2("Mike" ,"mike.gmail.com" ,"Verbitskogo 20", 4445);
    Client c3("Ilon" ,"ilon.gmail.com" ,"Lvivska 21", 4456);
    Client c4("John" ,"john.gmail.com" ,"Doroshenka 11", 4457);
    Client c5("Cristian" ,"cristian.gmail.com" ,"Bandery S. 2", 4458);
    Client c6("Oleh" ,"oleh.gmail.com" ,"Dzerelna 10", 4467);
    Client c7("Sue" ,"sue.gmail,com" ,"Pohulianka 12", 4468);
    Client c8("Karen" ,"karen.gmail.com" ,"Bukova 23", 4469);
    Client c9("Sasha-The best" ,"sasha.gmail.com" , "Horordotska 88 ", 4448);
    Client c10("Viktoria" ,"viktoria.gmail.com" ,"Pasichna 104", 4480);

 // Our cards

    Card cc1(c1, 33, 1000);
    Card cc2(c2, 45, 1001);
    Card cc3(c3, 78, 1002);
    Card cc4(c4, 69, 1003);
    Card cc5(c5, 200, 1004);
    Card cc6(c6, 139, 1005);
    Card cc7(c7, 345, 1006);
    Card cc8(c8, 399, 1007);
    Card cc9(c9, 323, 1008);
    Card cc10(c10, 990, 1009);

    Bank[0] = cc1;
    Bank[1] = cc2;
    Bank[2] = cc3;
    Bank[3] = cc4;
    Bank[4] = cc5;
    Bank[5] = cc6;
    Bank[6] = cc7;
    Bank[7] = cc8;
    Bank[8] = cc9;
    Bank[9] = cc10;

    while (true) {
        int option;
        cout << "Search by name 0, address 1, gmail address" << endl;
        cin >> option;

        string input;
        cout << "Enter" << endl;
        cin >> input;
        Card** filtered = new Card * [10];
        unsigned int count = 0;

        for (int i = 0; i < 10; i++) {
            if (Bank[i].checkFilter(option, input)) {
                filtered [count] = &Bank[i];
                cout << "#" << count << endl << Bank[i];
                count++;
            }
        }

        cout << "There are " << count << " accounts found" << endl << "Select one by entering it`s number in list" << endl;
        int n;
        cin >> n;

        cout << "Selected account bank" << endl << *filtered[n];

        cout << "0 to add money, 1 to remove money + amount of money: " << endl;
        int op;
        double money;
        cin >> op >> money;

        if (op == 0) {
            filtered[n]->addMoney(money);

        }
        else if (op == 1) {
            filtered[n]->removeMoney(money);
        }

        cout << "Operation is finished" << endl;
    }

}