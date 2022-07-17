#pragma once
#include "rule_node.h"



namespace jukebox {
	//Class that implement the mid or first node in a chain, that decide go to left or to right child by param compare.
	class IntNode : public RuleNode {
	public:
		//Store relevant info.
		IntNode(const std::wstring& node_type,
				int param,
				const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				int num);

		// Decide go to left or to right child.
		virtual std::string Handale(const Song& song) override;

	private:
		//To compare with song parameter.
		const int param_;
	};

}