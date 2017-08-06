//
// Created by Cory Brown on 15/07/2017.
//

#include "HTMLParser.h"

HTMLParser::HTMLParser(int arg_num, const char* program[]) {
	this->checkFile(arg_num, program);
	this->openHTML(program[1]);
}

void HTMLParser::checkFile(int arg_num, const char* program[]) {
	if (arg_num != 2) {
		cout << "insufficient number of arguments" << endl;
		cout << "usage: " << program[0] << " <HTML file>" << endl;
		exit(1);
	}
}

void HTMLParser::openHTML(const string & file) {

	string get_input;
	ifstream open_file(file);

	if (!open_file.is_open()) {
		cout << "ERROR opening file.\nExiting program..." << endl;
		exit(1);
	}

	while (open_file >> get_input) {
		input_tags += get_input;
	}

	open_file.close();
}


void HTMLParser::readHTML() {
	for (int i = 0; i < input_tags.length(); ++i) {
		if (input_tags[i] == '<' || input_tags[i] == '/') {
			if (input_tags[i] == '/') {
				--i;
			}
			string temp_tag = "";
			while (input_tags[i] != '>') {
				temp_tag += input_tags[i++];
			}
			this->tag.push_back(temp_tag);
		} else {
			string temp_text;
			while (input_tags[i] != '<') {
				temp_text += input_tags[i++];
			}
			this->tag.push_back(temp_text);
		}
	}
	this->formatHTML();
}

// Could spilt this up into two different functions, but it's fine for now.
void HTMLParser::formatHTML() {
	for (int i = 0; i < this->tag.size(); i++) {
		// Bold tag
		if ((this->tag[i]) == "<b") {
			++i;
			string &textContent = this->tag[i];
			textContent.insert(textContent.begin(), '*');
			textContent.push_back('*');

			// Italic tag
		} else if ((this->tag[i]) == "<i") {
			++i;
			string &textContent = this->tag[i];
			textContent.insert(textContent.begin(), '_');
			textContent.push_back('_');

			// Anchor tag
		} else if (((this->tag[i])[1]) == 'a') {
			string url = (this->tag[i]).substr(8);
			url.insert(url.begin(), '(');
			url.pop_back(); // this will remove the quotation mark at the end of the string
			url.push_back(')');
			string &textContent = this->tag[++i];
			textContent += " " + url;
		}
	}
}

void HTMLParser::printHTML() {
	for (int i = 0; i < this->tag.size(); i++) {
		if (((this->tag[i])[0]) != '<') {
			cout << this->tag[i] << endl;
		}
	}
}
