#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
    long a, b;
    cin >> a >> b;
    while (a != 0 and b != 0)
    {
        if (a > b) {
            a = a % b;
        }
        else { b = b % a; }
    }
    cout << a + b << endl;
    return 0;
}