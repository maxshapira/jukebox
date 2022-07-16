#include "terminal_node.h"



namespace jukebox {
	TerminalNode::TerminalNode(const std::string& song_status):
		song_status_{song_status}
	{

	}

	std::string TerminalNode::Handale(const Song& song)
	{
		return song_status_;
	}
}

