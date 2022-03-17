#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

vector <vector<int>> stack;

void insertsort(vector<int>& vec, int start, int end) {
	int i, j;

	for (i = start + 1; i <= end; i++) {
		int tmp = vec[i];
		for (j = i; ((j >= start + 1) && (vec[j - 1] > tmp)); j -= 1) {
			vec[j] = vec[j - 1];
		}
		vec[j] = tmp;
	}
}

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

int getrun(int n) {
	int mod2 = 0;
	while (n >= 64) {
		if ((n % 2) == 1) {
			mod2 = 1;
		}
		n /= 2;
	}
	return n + mod2;
}

vector<int> mergeparts() {
	vector<int> res;
	vector<int> tmp;
	res.resize(stack[0].size());
	copy(stack[0].begin(), stack[0].end(), res.begin());
	for (int i = 1; i < stack.size(); i++) {
		tmp = merge(res, stack[i]);
		res.clear();
		res.resize(tmp.size());
		copy(tmp.begin(), tmp.end(), res.begin());
		tmp.clear();
	}

	return res;
}

void timsort(vector<int>& vec, int minrun) {
	vector<int> tmp;
	int count = 1;
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i + 1] > vec[i]) {
			count++;
			if (i + 1 == vec.size() - 1) {
				tmp.resize(count);
				copy(vec.begin() + i + 1 - count, vec.begin() + i + 1, tmp.begin());
				stack.push_back(tmp);
				tmp.clear();
				//stack.push_back({ i + 1 - count, count });
			}
		}
		else {
			if (count < minrun) {
				insertsort(vec, i + 1 - count, min((i - count + minrun), (int)(vec.size() - 1)));
				tmp.resize(min(minrun, (int)(vec.size() - (i + 1 - count))));
				copy(vec.begin() + i + 1 - count, 
					vec.begin() + min((i - count + minrun + 1), (int)(vec.size())), tmp.begin());
				stack.push_back(tmp);
				tmp.clear();
				//stack.push_back({ i + 1 - count, min(minrun, (int)(vec.size() - (i + 1 - count))) });
				i = min((i - count + minrun), (int)(vec.size() - 1));
			}
			else {
				tmp.resize(count);
				copy(vec.begin() + i + 1 - count, vec.begin() + i + 1, tmp.begin());
				stack.push_back(tmp);
				tmp.clear();
				//stack.push_back({ i + 1 - count, count });
			}
			count = 1;
		}
	}

	vec.clear();
	vec = mergeparts();

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
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10, 14, -32, 100, -32, 0, 1, 10};

	int minrun = getrun(vec.size());

	timsort(vec, minrun);

	cout << "Size: " << vec.size() << endl;
	cout << "Minrun: " << minrun << endl;

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	cout << endl;

	unsigned int end = clock();

	cout << "Time: " << end - start << endl;

	return 0;
}