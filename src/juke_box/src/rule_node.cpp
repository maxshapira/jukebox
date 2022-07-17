#include "rule_node.h"
#include <iostream>
#include "string_converter.h"


namespace jukebox {

	RuleNode::RuleNode(const std::wstring& node_type,
					   const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
					   int num) :
		node_type_{ WstrToStr(node_type) },
		nodes_container_{nodes_container},
		num_{num}
	{
	}



	std::string RuleNode::Handale(const Song& song)
	{
		return this->Handale(song);
	}
}