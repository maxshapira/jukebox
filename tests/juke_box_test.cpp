#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "juke_box.h"



using namespace std;
using namespace jukebox;
using namespace nlohmann;;


class JukeBoxTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		std::ifstream songs_file("data/songs.json", std::ifstream::binary);

		songs_file >> songs;
	}

	json::value_type songs;
};




TEST_F(JukeBoxTest, MaeJRules) {
	JukeBox juke_box("data/mae-j");

	set<int> play_indexes{ 17,18,19 };

	for (int i = 0; i < songs.size(); i++) {
		auto song_status = juke_box.Play(songs[i]);
		auto found = play_indexes.find(i);
		if (found != play_indexes.end()) {
			EXPECT_EQ(song_status, "Play");
		}
		else {
			EXPECT_EQ(song_status, "Skip");
		}
	}
}



TEST_F(JukeBoxTest, BuzzARules) {
	JukeBox juke_box("data/buzz-a");

	set<int> play_indexes{ 11,15,16 };

	for (int i = 0; i < songs.size(); i++) {
		auto song_status = juke_box.Play(songs[i]);
		auto found = play_indexes.find(i);
		if (found != play_indexes.end()) {
			EXPECT_EQ(song_status, "Play");
		}
		else {
			EXPECT_EQ(song_status, "Skip");
		}
	}
}



TEST_F(JukeBoxTest, NeilARules) {
	JukeBox juke_box("data/neil-a");

	for (int i = 0; i < songs.size(); i++) {
		auto song_status = juke_box.Play(songs[i]);

		EXPECT_EQ(song_status, "Play");
	}
}