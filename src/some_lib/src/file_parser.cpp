#include "file_parser.h"
#include <codecvt>
#include <fstream>

using namespace std;

namespace jukebox {
	std::vector<std::wstring> ReadFile(const std::string& filename)
	{
		std::wifstream wif(filename);

		wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

		std::wstring part;
		std::vector<std::wstring> parts;

		while (std::getline(wif, part, L'\0')) {
			if (part != L"")
				parts.push_back(part);
		}

		return parts;
	}
}