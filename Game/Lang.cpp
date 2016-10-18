#include "Lang.h"
#include <iterator>

wchar_t* charToWChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}


bool Lang::inited = false;

size_t Lang::deflang = 0;
size_t Lang::selected = 0;

std::vector<std::string> Lang::languages;
std::map<std::string, std::string> Lang::m;


void Lang::init() {
	if (!inited) {
		inited = true;

		sf::String p;

#define DB(id, str) m[p+id]=str;

#include "lang\pl.inc"
		languages.push_back(p);

#include "lang\en.inc"
		languages.push_back(p);
	}
}

std::string Lang::translateRaw(std::string in) {
	std::string out;

	if (m.find(languages[selected] + in) != m.end()) {
		out = m.at(languages[selected] + in);
	}
	else if (m.find(languages[deflang] + in) != m.end()) {
		out = m.at(languages[deflang] + in);
	}
	else {
		out = in;
	}

	return out;
}

wchar_t* Lang::translate(std::string in) {
	return charToWChar(translateRaw(in).c_str());
}