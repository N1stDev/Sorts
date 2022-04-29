#include<iostream>
#include<vector>

using namespace std;

int main() {
	unsigned int start = clock();
	vector<int> vec = { 1, 10, -29, 0, 14, -32, 100, -32, 0 };
	
	int n = vec.size();
	int tmp, j;

	for (int i = 1; i < n; i++) {
		int tmp = vec[i];
		for (j = i; ((j >= 1) && (vec[j - 1] > tmp)); j -= 1) {
			vec[j] = vec[j - 1];
		}
		vec[j] = tmp;
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}

	cout << endl;
	unsigned int end = clock();
	cout << "Time:" << end - start << " ms" << endl;

	return 0;
}
