// Supported <html>, <head>, <body>, <b>, <i>, and <a>

#include "HTMLParser.h"

int main(int argc, const char *argv[]) {

	cout << "HTML Parser\n" << endl;

	HTMLParser html(argc, argv);
	html.readHTML();
	html.printHTML();
}