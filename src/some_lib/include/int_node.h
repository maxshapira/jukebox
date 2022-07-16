#pragma once
#include "rule_node.h"



namespace jukebox {
	class IntNode : public RuleNode {
	public:
		ListNode(const std::string& node_type,
				 int param,
				 std::shared_ptr<Node> left,
				 std::shared_ptr<Node> right);

		virtual std::string Handale(const Song& song) override;

	private:
		const int param_;
	};

}