#pragma once
#include "rule_node.h"



namespace jukebox {
	class IntNode : public RuleNode {
	public:
		IntNode(const std::wstring& node_type,
				int param,
				const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				int num);

		virtual std::string Handale(const Song& song) override;

	private:
		const int param_;
	};

}