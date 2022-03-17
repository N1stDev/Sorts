#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

vector<int> merge(vector<int> first, vector<int> second) {
	int f_i = 0, s_i = 0;
	vector<int> res;
	while ((f_i < first.size()) && (s_i < second.size())) {
		if (first[f_i] > second[s_i]) {
			res.push_back(second[s_i]);
			s_i++;
		}
		else {
			res.push_back(first[f_i]);
			f_i++;
		}
	}

	for (int i = f_i; i < first.size(); i++) {
		res.push_back(first[f_i]);
	}
	for (int i = s_i; i < second.size(); i++) {
		res.push_back(second[s_i]);
	}
	
	return res;
}

vector<int> mergesort(vector<int>& vec, int start, int end) {
	vector<int> left;
	vector<int> right;
	if (end - start == 0) {
		return { vec[start] };
	}
	int middle = start + ((end - start) / 2);
	left = mergesort(vec, start, middle);
	right = mergesort(vec, middle + 1, end);

	return merge(left, right);
}

int main() {

	unsigned int start = clock();

	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10,
		-29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0, 1,
		10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10, 14, -32, 100, -32, 0, 1, 10 };
	vec = mergesort(vec, 0, vec.size() - 1);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	cout << endl;

	unsigned int end = clock();

	cout << "Time: " << end - start << endl;

	return 0;
}