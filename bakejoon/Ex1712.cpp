#include<iostream>

using namespace std;

int main()
{
    long long n = 0;
    cin >> n;

    int dist = 1;
    long long rangeStart = 1;
    long long roomCount = 1;

    while (true) {

        rangeStart = rangeStart + roomCount;

        if (n < rangeStart) {
            break;
        }

        roomCount = dist * 6;
        dist++;
    }
    cout << dist << endl;
}
