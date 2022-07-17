#include <fstream>
#include <iostream>
#include <set>
#include "juke_box.h"



using namespace jukebox;
using namespace nlohmann;



int main() {
	std::string file{ "data/mae-j" };

	//parse a rule configuration
	JukeBox juke_box(file);

	//evaluate a list of songs
	std::ifstream songs_file("data/songs.json", std::ifstream::binary);

	json::value_type songs;

	songs_file >> songs;

	//determine which of them will be allowed to play, according to the rules
	for (const auto& song : songs) {
		auto song_status = juke_box.Play(song);

		std::cout << song_status << " " << song["Title"] << std::endl;
	}
}


