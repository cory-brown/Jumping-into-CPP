#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

template <typename T> void sortVector(vector<T>& vec);

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<int> nums(10);


	for (int &num : nums) {
		int rand_nums = (rand() % 10) + 1;
		num = rand_nums;
	}

	sortVector(nums);

	for (int num : nums) {
		cout << num << endl;
	}
}

template<typename T>
void sortVector(vector<T>& vec) {
	int j, temp;
	for (int i = 1; i < vec.size(); i++) {
		j = i;
		while (j > 0 && vec[j - 1] > vec[j]) {
			temp = vec[j];
			vec[j] = vec[j - 1];
			vec[j - 1] = temp;
			j--;
		}
	}
}