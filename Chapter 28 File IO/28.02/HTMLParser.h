//
// Created by Cory Brown on 15/07/2017.
//

#ifndef INC_28_02_HTMLPARSER_H
#define INC_28_02_HTMLPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class HTMLParser {
private:
		vector<string> tag;
		string input_tags;
public:
		// this function contains:
		// checkFile(), openHTML()
		HTMLParser(int, const char*[]);

		// checks if the the amount of arguments passed
		void checkFile(int, const char*[]);

		// opens file that is passed and will read the HTMl
		void openHTML(const string&);

		// Reads in the HTML and adds tags to vector
		void readHTML();

		//  adds the formatting to the tags
		void formatHTML(); // called in readHTML

		// iterators through the vector that is passed in (which should contain the HTML tags)
		void printHTML();
};

#endif //INC_28_02_HTMLPARSER_H
