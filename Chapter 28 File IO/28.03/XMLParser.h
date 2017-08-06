//
// Created by Cory Brown on 16/07/2017.
//

#ifndef INC_28_03_XMLPARSER_H
#define INC_28_03_XMLPARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

namespace Parser {

		class Node {
		public:
				virtual void nodeStart(ifstream& tag) = 0;
				virtual void attributeRead(string& attribute) = 0;
				virtual bool nodeTextRead(ifstream& textNode) = 0;
				virtual void nodeEnd(string&  endNode) = 0;
		};

		class XMLParser : public Node {
		public:
				XMLParser(const string& fileName);
				void nodeStart(ifstream& tag);
				void attributeRead(string& attribute);
				bool nodeTextRead(ifstream& textNode);
				void nodeEnd(string& endNode);
		private:
				int _indent_val;
				int _indent_size;
		};
}

#endif //INC_28_03_XMLPARSER_H
