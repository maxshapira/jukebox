#include "terminal_node.h"
#include <iostream>



namespace jukebox {
	TerminalNode::TerminalNode(const std::wstring& song_status) :
		song_status_{ song_status.begin(), song_status.end() }
	{

	}

	std::string TerminalNode::Handale(const Song& song)
	{
		return song_status_;
	}
}

