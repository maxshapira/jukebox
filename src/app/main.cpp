#include "file_parser.h"
#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>

using namespace std;


using namespace nlohmann;


int main() {

	std::ifstream people_file("data/songs.json", std::ifstream::binary);
	json::value_type people;
	people_file >> people;

	//cout << people; //This will print the entire json object.
	//cout << people.front(); //This will print the entire json object.
	cout << people.front()["Artist"]; //This will print the entire json object.





	//auto wstrs = jukebox::ReadFile("data/songs.json");
	//std::ifstream people_file("data/songs.json", std::ifstream::binary);
	//json jf = json::parse(people_file);
	//auto b = jf.front().front().front().front().front();
	//people_file >> people;

	//cout << people; //This will print the entire json object.

	////The following lines will let you access the indexed objects.
	//cout << people["Anna"]; //Prints the value for "Anna"
	//cout << people["ben"]; //Prints the value for "Ben"
	//cout << people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

	//cout << people["profession"]; //NULL! There is no element with key "profession". Hence a new empty element will be created.
	int a = 0;
}
