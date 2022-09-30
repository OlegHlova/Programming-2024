#include <iostream>
#include <string>
#include<math.h>
using namespace std;



int main()
{
	int A;
	int B;
	float aref;
	float geom;
	cout << "Enter the number A:" << endl;
	cin >> A;
	cout << "Enter the number B:" << endl;
	cin >> B;
	aref = (A + B) / 2;
	geom = sqrt((A * B));
	cout << "Arithmetic average value = " << aref << endl;
	cout << "Geometric mean value = " << geom << endl;

	return 0;
}