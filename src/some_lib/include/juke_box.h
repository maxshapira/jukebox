#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "node.h"



namespace jukebox {
	class JukeBox {
	public:
		JukeBox(const std::string& filename);

		std::string Play(const Song& song);

	private:
		void Container(const std::string& filename);

		std::unordered_map<int, std::shared_ptr<Node>> nodes_container_;

		std::shared_ptr<Node> CreateNode(int num, 
										 const std::wstring& n_type,
										 std::vector<std::wstring>::iterator& it);

		std::vector<std::wstring> ReadFile(const std::string& filename);
	};
}