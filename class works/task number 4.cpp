#include <iostream>
#include <string>
#include <math.h>
 
using namespace std; 

int main()
{
	unsigned long long n, b;
       long long a;
	     cin >> n; 
		 b = 0; 
		 while (n > 0) {
			 a = n %10; 
			 b *= 10;
			 b += a;
		 }
		 cout << b << endl;
		 return 0;

}