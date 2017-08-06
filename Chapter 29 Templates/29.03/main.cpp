#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
bool search(const vector<Type>& vec, const Type& value);

int main() {
	vector<int> nums(10);

	for (int i = 0; i < 10; ++i) {
		nums[i] = (i * i) + 1;
	}

	cout << "Enter Value: ";
	int val;
	cin >> val;
	cin.ignore();

	search(nums, val) ?
	cout << val << " found in vector" << endl
	                 :
	cout << val << " not in vector" << endl;
}

template <typename Type>
bool search(const vector<Type>& vec, const Type& value) {
	for (int i = 0; i < vec.size(); ++i) {
		if (value == vec[i]) {
			return true;
		}
	}
	return false;
}