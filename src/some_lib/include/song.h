#pragma once
#include <nlohmann/json.hpp>


namespace jukebox {
	struct Song {
		Song(const nlohmann::json::value_type&);

		const std::string title;
		const std::string artist;
		const std::string genre;
		const int length;
		const int bpm;
	};
}