#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

void HibbardStep(vector<double>& vec, int n) {
	int i = 1;
	while ((pow(2, i) - 1) <= n) {
		vec.push_back(pow(2, i) - 1);
		i++;
	}
}

void SedgewickStep(vector<double>& vec, int n) {
	int i = 0;
	double step;
	while (1) {
		if (i % 2 == 0) {
			step = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
			if (3 * step > n) {
				break;
			}
			vec.push_back(step);
			i++;
		}
		else {
			step = 8 * pow(2, i) - 6 * pow(2, (i+1) / 2) + 1;
			if (3 * step > n) {
				break;
			}
			vec.push_back(step);
			i++;
		}
	}
}

int main() {
	unsigned int start = clock();
	vector<int> vec = { 1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10,
		-29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0, 1,
		10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10,
		-29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0, 1,
		10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10 ,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10,
		-29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0, 1,
		10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10, -29, 0, 14, -32, 100, -32, 0,
	1, 10, -29, 0, 14, -32, 100, -32, 0, 1, 10 };
	vector<double> steps;
	int n = vec.size(), j;

	HibbardStep(steps, n);

	for (int s = steps.size() - 1; s >= 0; s--) {
		for (int i = steps[s]; i < n; i++) {
			int tmp = vec[i];
			for (j = i; ((j >= steps[s]) && (vec[j - steps[s]] > tmp)); j -= steps[s]) {
				vec[j] = vec[j - steps[s]];
			}
			vec[j] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;

	unsigned int end = clock();
	cout << "Time:" << end - start << " ms" << endl;

	return 0;
}