#pragma once
#include <string>


namespace jukebox {
	struct Node{
		Node(int num, std::string type);

		bool IsTerminal();

		const int num;

		const std::string type;

		Node* left;

		Node* right;
	};
}