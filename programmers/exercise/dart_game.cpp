#include <string>
#include <iostream>
#include <memory.h>

#include <math.h>

using namespace std;
int solution(string dartResult) {
int answer;
  string a;
	a = dartResult;
	
	int aval[3] = { 0 };
	memset(aval, 0, sizeof(aval));
	int i = 0;
	int cnt = 0;
	int flag = 0;


	while (a.length() > i)
	{
		if (a.at(i) >= 'A' && a.at(i) <= 'Z') {
			if ( a.at(i) == 'S') {
				aval[cnt -1] = pow(aval[cnt -1], 1);
			} else if (a.at(i) == 'D') {
				aval[cnt -1] = pow(aval[cnt -1], 2);
			} else if (a.at(i) == 'T') {
				aval[cnt -1] = pow(aval[cnt -1], 3);
			}
		} else if (a.at(i) == '*') {
			if (cnt == 0) {
				aval[cnt -1] * 4;
			} else {
				aval[cnt - 2] *= 2;
				aval[cnt -1] *= 2;
				
			}
		} else if (a.at(i) == '#') {
			aval[cnt -1] *= -1;
		} else {
			aval[cnt] = (aval[cnt]) * 10 + (a.at(i)-'0');
			if (a.at(i+1) - '0' >= 0 && a.at(i+1) - '0' <= 10) {

			} else {
			    cnt++;
		    }
		}
		i++;
	}

	int result = 0;
	result = aval[0] + aval[1] + aval[2];
    answer = result;
    return answer;
}
