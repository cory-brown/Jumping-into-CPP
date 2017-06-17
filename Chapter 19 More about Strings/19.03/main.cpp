/*
Write a program that reads in HTML text that the user types in (don’t worry, we’ll cover how to
read from a file later). It should support the following HTML tags: <html>, <head>, <body>, <b>,
<i>, and <a>. Each HTML tag has an open tag, e.g. <html>, and a closing tag which has a forwardslash
at the start: </html>. Inside the tag is text that is controlled by that tag: <b>text to be
bolded</b> or <i>text to be italicized</i>. The <head> </head> tags control text that is
metadata, and the <body></body> tags surround text that is to be displayed. <a> tags are used
for hyperlinks, and have an URL in the following format: <a href=URL>text</a>.


Once your program has read in some HTML, it should simply ignore <html>. It should remove
any text from the <head> section so that it doesn't show up when you output it. It should then
display all text in the body, modifying it so that any text between a <b> and a </b> will show up
with asterisks (*) around it, any text inside <i> and </i> will show up with underscores (_)
around it, and any text with a <a href=linkurl>link text</a> tag shows up as link text (linkurl).
*/


//Supported <html>, <head>, <body>, <b>, <i>, and <a>


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readHTML(vector<string>&, const string&);
void formatHTML(vector<string>&);
void printHTML(const vector<string>&);

int main() {
	vector<string> tags;
  string input_tag = "<html><head></head><body><i>Hello</i><b>World</b><a href=google.com>Visit Google!</a></body></html>";


	readHTML(tags, input_tag);
  formatHTML(tags);
  printHTML(tags);
}

//  READ THIS LATER
//  http://stackoverflow.com/questions/9221980/how-would-i-store-an-empty-string-into-a-vector
//

void readHTML(vector<string>& tags, const string& html) {
  for (int i = 0; i < html.length(); ++i) {
    if (html[i] == '<' || html[i] == '/') {
			if (html[i] == '/') {
				--i;
			}
      string temp_tag = "";
      while (html[i] != '>') {
        temp_tag += html[i++];
      }
      tags.push_back(temp_tag);
    } else {
      string temp_text;
      while (html[i] != '<') {
        temp_text += html[i++];
      }
      tags.push_back(temp_text);
    }
  }
}

// Could spilt this up into two different functions, but it's fine for now.
void formatHTML(vector<string>& tags) {
	for (int i = 0; i < tags.size(); i++) {
		if ((tags[i]) == "<b") {
			++i;
			string &textContent = tags[i];
			textContent.insert(textContent.begin(), '*');
			textContent.push_back('*');
		} else if ((tags[i]) == "<i") {
			++i;
			string &textContent = tags[i];
			textContent.insert(textContent.begin(), '_');
			textContent.push_back('_');
		} else if (((tags[i])[1]) == 'a') {
			string url = (tags[i]).substr(8);

			url.insert(url.begin(), '(');
			url.push_back(')');
			string &textContent = tags[++i];
			textContent += " " + url;
		}
	}
}

void printHTML(const vector<string>& tags) {
	for (int i = 0; i < tags.size(); i++) {
		if (((tags[i])[0]) != '<') {
				cout << tags[i] << endl;
		}
	}
}
