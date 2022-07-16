#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "nodes_container.h"



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



TEST_F(JukeBoxTest, FirstSong) {
	NodesContainer container("data/mae-j");

	auto song_status = container.Play(songs.front());

	EXPECT_EQ(song_status, "Play");
}