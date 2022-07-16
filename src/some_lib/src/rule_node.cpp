#include "rule_node.h"


namespace jukebox {

	RuleNode::RuleNode(const std::wstring& node_type,
					   std::shared_ptr<Node> left,
					   std::shared_ptr<Node> right) :
		node_type_{ node_type_.begin(), node_type_.end()},
		left_{ left },
		right_{ right }
	{
	}



	std::string RuleNode::Handale(const Song& song)
	{
		return this->Handale(song);
	}

}