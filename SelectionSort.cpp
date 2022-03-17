#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> vec = { 1, 10, -29, 0, 14, -32, 100, -32, 0 };
	int n = vec.size();
	int min = 999;
	int min_pos = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (vec[j] <= min) {
				min = vec[j];
				min_pos = j;
			}
		}
		vec.push_back(vec[min_pos]);
		vec.erase(vec.begin() + min_pos);
		min = 999;
		min_pos = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}

	return 0;
}