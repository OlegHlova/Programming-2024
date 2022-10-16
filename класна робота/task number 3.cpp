#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n= "; 
    cin >> n; 
    int u0 = 0, u1 = 1, u;
    cout << u0 << endl; 
    cout << u1 << endl; 
    for (int i = 2; i <= n; i++)
    {
    u = u0 + u1; 
    cout << u << endl; 
    u0 = u1;
    }
    return 0;
}