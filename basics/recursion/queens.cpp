/*
 설계:
1. 퀸을 놓을때 같은 열이나 대각 선에 있으면 두지 못하게 한다.
2. 다음 행으로 넘어가 동일하게 검사한다.
3. 1~2 를 반복하면서 N개의 퀸이 다 놓였있는지 검사한다.

1. 1,1 에 퀸을 놓으면 열 1은 전부다 둘수 없게 된다.
2. 대각 선을 검사하기 위해 방금 앞단계에서 놓여진 것을 검사한다.
3. 2차열 배열을 선언하지 않고 앞서 몇번째 퀸이 몇번째 열에만 놓였는지만 검사해본다.
4. cols 배열
*/

#include<iostream>
#include<Math.h>
using namespace std;

bool promising(int level);
bool queens(int level);
int *cols;

// 퀸의 숫자
int N = 0;

int main() {
	cout << "Input queens count: ";
	cin >> N;

	cols = new int[N + 1];

	if (queens(0)) {
		cout << "성공" << endl;
	} else {
		cout << "실패" << endl;
	}
}

// 퀸을 둘수 있는지 검사 하는 함수.
bool promising(int level) {
	for (int i = 0; i < level; i++) {
		// column 검사
		if (cols[i] == cols[level]) {
			return false;
	    
		// 대각선 검사. 거리공식 
		} else if (level - i == abs(cols[i] - cols[level])) {
			return false;
		}
	}
	return true;
}

// 퀸을 내려두는 함수
bool queens(int level) {

	// 퀸을 둘수 있는지 검사
	if (!promising(level)) {
		return false;

	// 해답 찾음.
	} else if (level == N) { 
		return true;

	// 더 놓을수 있는지 재귀 호출
	} else {

		// 놓을수 있는 queen 검사
		for (int i = 1; i <=N; i++) {
			// 해당 퀸을 i 번째에 두었음.
			cols[level + 1] = i;

			// 재귀 함수 호출 만일 true면 더이상 다음걸 검사할 이유가 없음.
			if (queens(level + 1)) {
				return true;
			}
		}
	}

	// 있는 데 까지 해봤지만 둘수 없음
	return false;
}
