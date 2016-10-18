#pragma once
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "S.h"

wchar_t* charToWChar(const char* text);

class Lang {
private:
	static bool inited;

	static size_t deflang;
	static size_t selected;

	static std::vector<std::string> languages;
	static std::map<std::string, std::string> m;
public:

	static void init();
	static wchar_t* translate(std::string in);
	static std::string translateRaw(std::string in);
	static inline const std::vector<std::string>& getLanguages() { return languages; }
	static inline const std::string& getSelected() { return languages[selected]; }
	static inline const void set2Next() { ++selected; if (selected == languages.size()) { selected = 0; } } 
	static inline const void set2Prev() { --selected; if (selected == 0) { selected = languages.size() - 1; } }
};

#define l(IN) Lang::translate(IN)

