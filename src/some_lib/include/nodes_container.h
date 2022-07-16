#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "node.h"



namespace jukebox {
	class NodesContainer {
	public:
		NodesContainer(const std::string& filename);

		const std::unordered_map<int, std::shared_ptr<Node>> nodes_container_;

	private:
		std::unordered_map<int, std::shared_ptr<Node>> Container(const std::string& filename);

		std::vector<std::wstring> ReadFile(const std::string& filename);
	};
}