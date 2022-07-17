#pragma once
#include "node.h"



namespace jukebox {
	//class that implement the last node in a chain that must return value
	class TerminalNode : public Node {
	public:
		//store the status of song to return
		TerminalNode(const std::wstring& song_status);

		// return skip or play
		virtual std::string Handale(const Song& song) override;

	private:
		const std::string song_status_;
	};
}