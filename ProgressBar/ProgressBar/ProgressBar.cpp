// ProgressBar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>  
#include <chrono>
using namespace std;


	int main() {
		int progress = 0;
		int position = progress + 1;

		std::cout << "[";
		for (progress=0; progress < 100; ++progress) {
			if (position > progress) {
				std::cout << "=";
			} else if (progress == position) {
				std::cout << ">";
			}
			else {
				std::cout << "" << endl;
			}
		}
		std::cout << "]" << progress << "%" << std::endl;
		cin.get();


    return 0;
}

