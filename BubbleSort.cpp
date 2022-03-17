#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> vec = { 1, 10, -29, 0, 14, -32, 100, -32, 0 };
	int n = vec.size();
	int tmp;

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (vec[j] > vec[j+1]) {
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}

	return 0;
}