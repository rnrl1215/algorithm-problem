#include<iostream>
using namespace std;

void combination(int arr[], int n, int r, int index, int target, int comb[])
{
	cout << "N: " << n << " R: " << r << " index: " << index << " Target: " << target << endl;
	if (r == 0) {
		for (int i = 0; i < index; i++) {
			cout << comb[i];
		}
		cout << endl;
	} else if (target == n) {
		return;
	} else {
		comb[index] = arr[target];
		combination(arr, n, r - 1, index + 1, target + 1, comb);
		combination(arr, n, r, index, target + 1, comb);
	}
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int n = 5;
	int r = 3;

	int* comb = new int[5];
	combination(arr, 5, 3, 0, 0, comb);
}
