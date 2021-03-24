#include<iostream>
#include<string>

using namespace std;

void printCharReverse(string str);

int main()
{
    string name = "skahn";
    printCharReverse(name);
}

void printCharReverse(string str)
{
    if (str.length() == 0) {
        return;
    }
    else {
        printCharReverse(str.substr(1));
        cout << str.at(0);
    }
}
