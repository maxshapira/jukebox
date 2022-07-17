#pragma once
#include <string>
#include <nlohmann/json.hpp>



namespace jukebox {
	//typedef
	using Song = nlohmann::json::value_type;



	//The Node declares a method for executing a song request
	struct Node {
		virtual std::string Handale(const Song& song) = 0;
	};
}