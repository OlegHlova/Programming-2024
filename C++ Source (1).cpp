#include <iostream>
#define _Use_Math_Defines
#include <cmath>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	// ввести R - радіус і обчислити довжину кола
	float r;
	cout << "Enter the radius" << endl;
	cin >> r; 
	float l;
	float s;
	float v;	
	l = (r * 2) * M_PI;
	s = pow(r, 2) * M_PI;
	v = 4 / 3 * M_PI * pow(r, 3);
	cout << "Circle length=" << 1 << endl << "Circle area=" << s << endl << "Volume of the sphere=" << v << endl;
	
	return 0;
}

