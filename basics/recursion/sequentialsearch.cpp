#include<iostream>
#include<string>

using namespace std;

// iteration Implicit 
int searchI(int data[], int n , int target );

// recursion Explicit
int searchR(int data[], int begin, int end, int target);


int main()
{
    string name = "skahn";
    int data[10] = {1, 2, 6, 7, 98, 9, 5};
    cout<< searchI(data, 10, 5) << endl;
    cout<< searchR(data, 0, 10, 5) << endl;

}

// iteration
int searchI(int data[], int n, int target)
{
    for (int i = 0; i < n; i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

//recursion
int searchR(int data[], int begin, int end, int target)
{
    if (begin > end) {
        return -1;
    } else if (target == data[begin]) {
        return begin;
    } else {
        return searchR(data, begin + 1, end, target);
    }
}