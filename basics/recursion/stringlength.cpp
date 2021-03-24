#include<iostream>
#include<string>

using namespace std;

int length(string str);

int main()
{
    string name = "skahn";
    cout << length(name) << endl;
}

int length(string str)
{
    if (str=="") {
        return 0;
    } else {
        return (1 + length(str.substr(1)));
    }
}
