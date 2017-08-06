#include <iostream>
#include <vector>

using namespace std;

template <typename T>

T sumOfVector(vector<T>& vec) {
	T sum = T(); // T() set a default value for sum
	for (vector<int>::size_type i = 0; i < vec.size(); ++i) {
		sum += vec[i];
	}
	return sum;
}

int main() {
	vector<int> ints(10);
	vector<double> doubles(10);
	vector<float> floats(10);

	for (int i = 0; i < ints.size(); ++i) {
		ints[i] = i * i;
	}

	for (int i = 0; i < doubles.size(); ++i) {
		doubles[i] = (i / 9) * 0.000008;
	}

	for (int i = 0; i < floats.size(); ++i) {
		floats[i] = (i / 7) * 0.003f;
	}

	cout << sumOfVector(ints) << endl;
	cout << sumOfVector(doubles) << endl;
	cout << sumOfVector(floats) << endl;
}