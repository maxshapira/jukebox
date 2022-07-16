#include "file_parser.h"
#include "song.h"

#include <fstream>
#include <iostream>
#include <set>

using namespace std;
using namespace jukebox;


using namespace nlohmann;


int main() {

	std::ifstream songs_file("data/songs.json", std::ifstream::binary);
	json::value_type songs;
	songs_file >> songs;
	Song song{ songs.front() };

	auto wstrs = jukebox::ReadFile("data/mae-j");

	for (auto it = wstrs.begin(); it != wstrs.end();) {
		auto num = *it++;
		auto n_type = *it++;
		if (n_type == L"Artist") {
			auto begin = it + 1;
			auto end = it + 1 + (* it).front();

			set<wstring> artists(begin, end);
			wstring art (song.artist.begin(), song.artist.end());
			auto artist = artists.find(art);
			if (artist == artists.end()) {
				cout << "not find" << endl;
			}
			else {
				cout << "find" << endl;
			}
			int b = 0;
		}
	}
}
