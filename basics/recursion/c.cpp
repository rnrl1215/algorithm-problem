#include<iostream>

using namespace std;

double gcd(int m, int n);

int main()
{
    gcd(48, 7);
}

double gcd(int m, int n)
{
    
    cout << "M:" << m << endl;
    cout << "N: "<< n << endl;
    
    if (m < n)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }

    if (m % n == 0) {
        return n;
    } else {
        gcd(n, m%n);
    }
}
