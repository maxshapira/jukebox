#include "rule_node.h"


namespace jukebox {

	RuleNode::RuleNode(const std::string& node_type, std::shared_ptr<Node> left, std::shared_ptr<Node> right):
		node_type_{node_type},
		left_{left},
		right_{right}
	{
	}



	std::string RuleNode::Handale(const Song& song)
	{
		this->Handale(song);
	}

}