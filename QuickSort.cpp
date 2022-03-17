#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int rebuild(vector<int>& vec, int left, int right) {
	int mid = (right + left) / 2;
	int x = vec[mid];

	int left_pos = left;
	int mid_new_pos=0;

	for (int i = left; i <= right; i++) {
		if (vec[i] <= x) {
			if (i == mid) {
				mid_new_pos = left_pos;
			}
			swap(vec[i], vec[left_pos]);
			left_pos++;
		}
	}
	swap(vec[left_pos - 1], vec[mid_new_pos]);

	return left_pos - 1;
}

void quicksort(vector<int>& vec, int left, int right) {
	if (left < right) {
		int mid = rebuild(vec, left, right);
		quicksort(vec, left, mid - 1);
		quicksort(vec, mid + 1, right);
	}
}

int main() {
	unsigned int start = clock();
	vector<int> vec = { 1, 10, -29, 0, 14, -32, 100, -32, 0 };
	quicksort(vec, 0, vec.size() - 1);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;

	unsigned int end = clock();

	cout << "Time: " << end - start << endl;

	return 0;
}