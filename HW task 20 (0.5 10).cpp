#include <iostream>


using namespace std; 
  
int main() {

	int a;
	int v;
	int c;
	cout << "Enter the first number: " << endl;
	cin >> a;
	cout << "Enter the second number " << endl;
	cin >> v;
	cout << "Enter the third number " << endl;
	cin >> c;
	if ((a + v) / 2 == c) {
		cout << "Yes, they can";

	}
	else if ((a + c) / 2 == v) {
		cout << "Yes, they can";
	}
	else if ((v + c) / 2 == a) {
		cout << "Yes< they can";
	}
	else {
		cout << "No, they can`t";
	}
	return 0;


