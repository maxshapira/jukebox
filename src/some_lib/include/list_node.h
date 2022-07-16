#pragma once
#include "rule_node.h"



class ListNode : public RuleNode {
public:
	ListNode(const std::string& node_type,
			 const set<wstring>& list_options,
			 std::shared_ptr<Node> left,
			 std::shared_ptr<Node> right);

	virtual std::string Handale(const Song& song) override;

private:
	const std::string node_type_;

	const std::shared_ptr<Node> left_;

	const std::shared_ptr<Node> right_;
};