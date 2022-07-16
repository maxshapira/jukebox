#include "node.h"

bool jukebox::Node::IsTerminal()
{
	bool is_terminal{false};

	if (type == "Skip" || type == "Play") {
		is_terminal = true;
	}

	return is_terminal;
}
