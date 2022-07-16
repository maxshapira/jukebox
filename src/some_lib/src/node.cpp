#include "node.h"



namespace jukebox {
	bool jukebox::Node::IsTerminal()
	{
		bool is_terminal{ false };

		if (type == "Skip" || type == "Play") {
			is_terminal = true;
		}

		return is_terminal;
	}

	Node::Node(int num, const std::string& type):
		num{num}, type{type}
	{

	}

}
