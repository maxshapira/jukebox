#pragma once
#include <string>


namespace jukebox {
	//forward declaration
	class Song;



	//interface for nodes
	struct Node{
		virtual std::string Handale(const Song& song);
	};
}