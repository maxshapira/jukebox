#pragma once
#include <string>
#include <nlohmann/json.hpp>


namespace jukebox {
	//typedef
	using Song = nlohmann::json::value_type;



	//interface for nodes
	struct Node{
		virtual std::string Handale(const Song& song);
	};
}