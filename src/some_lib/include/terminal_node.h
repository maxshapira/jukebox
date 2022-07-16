#pragma once
#include "node.h"



namespace jukebox {
	class TerminalNode : public Node {
	public:
		TerminalNode(const std::wstring& song_status);

		virtual std::string Handale(const Song& song) override;

	private:
		const std::string song_status_;
	};
}