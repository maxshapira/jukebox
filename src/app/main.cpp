#include <fstream>
#include <iostream>
#include <set>
#include "juke_box.h"



using namespace std;
using namespace jukebox;
using namespace nlohmann;



int main() {
	std::ifstream songs_file("data/songs.json", std::ifstream::binary);
	json::value_type songs;
	songs_file >> songs;
	std::string file{ "data/mae-j" };
	JukeBox juke_box(file);
	auto a = juke_box.Play(songs.front());
	int ao = 0;
}


