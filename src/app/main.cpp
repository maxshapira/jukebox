#include <fstream>
#include <iostream>
#include <set>
#include "nodes_container.h"



using namespace std;
using namespace jukebox;
using namespace nlohmann;



int main() {
	std::ifstream songs_file("data/songs.json", std::ifstream::binary);
	json::value_type songs;
	songs_file >> songs;
	std::string file{ "data/mae-j" };
	NodesContainer container(file);
	auto a = container.Play(songs.front());
	cout << a << endl;
	int ao = 0;
}


