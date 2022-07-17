#include "terminal_node.h"
#include <iostream>
#include "string_converter.h"



namespace jukebox {
	TerminalNode::TerminalNode(const std::wstring& song_status) :
		song_status_{ WstrToStr(song_status)}
	{

	}

	std::string TerminalNode::Handale(const Song& song)
	{
		return song_status_;
	}
}

