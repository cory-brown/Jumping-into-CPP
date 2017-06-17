
// 1. Write a recursive algorithm to compute the power function pow(x, y) = x^y

#include <iostream>

using namespace std;

int powerFun(int base, int exponent) {

  if (exponent <= 0) {
    return 1;
  } else {
    return base * powerFun(base, exponent - 1);
  }
}

int main() {
  int base, exponent;
  base = exponent = 0;
  cout << "Enter base value: ";
  cin >> base;
  cout << "Enter exponent: ";
  cin >> exponent;

  cout << base << "^" << exponent << "=";
  cout << powerFun(base, exponent) << endl;
}

// Pattern of recursion
// 1
//   2
//     3
//       4
//         5
//           6
//             7
//               8
//                 9
//
//                 9
//               8
//             7
//           6
//         5
//       4
//     3
//   2
// 1
