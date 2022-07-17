#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "node.h"



namespace jukebox {
	//This class parse a rule configuration and determine if song allowed to play, according to the rules.
	class JukeBox {
	public:
		//Create container with all the rules inside.
		JukeBox(const std::string& filename);

		//Determine if song allowed to play
		std::string Play(const Song& song);

	private:
		//Build the container with rules
		void BuildContainer(const std::string& filename);

		//create a single rule node
		std::shared_ptr<Node> CreateNode(int num, 
										 const std::wstring& n_type,
										 std::vector<std::wstring>::iterator& it);

		//parse file with rules
		std::vector<std::wstring> ReadFile(const std::string& filename);

		//container that hold the rules for choosing the songs
		std::unordered_map<int, std::shared_ptr<Node>> nodes_container_;
	};
}