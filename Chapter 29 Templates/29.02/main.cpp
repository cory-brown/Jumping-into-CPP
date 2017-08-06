#include "newVector.hxx"
#include "newVector.cpp" // this prevents a linker error when using templates

using namespace zero_vector;

int main() {
	new_vector<int> newVector(1);
	newVector.pushBack(5);
	cout << newVector[0] << endl;

	new_vector<string> anotherVec(1);
	anotherVec.pushBack("Cory");
	cout << anotherVec[0] << endl;

	new_vector<double> oneMore(1);
	oneMore.pushBack(0.0005);
	cout << oneMore[0] << endl;

}