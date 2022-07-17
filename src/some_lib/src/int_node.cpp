#include "int_node.h"
#include <codecvt>
#include <iostream>



namespace jukebox {
	IntNode::IntNode(const std::wstring& node_type,
					  int param,
					 const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
					 int num):
		RuleNode{node_type, nodes_container,num },
		param_{param}
	{

	}



	std::string IntNode::Handale(const Song& song)
	{
		auto param = song[node_type_];

		//test node evaluates as `true` we move to it's left child
		if (param <= param_) {
			return nodes_container_.at(num_*2)->Handale(song);
		}
		//if `false` we move to the right child
		else {
			return nodes_container_.at(num_ * 2 + 1)->Handale(song);
		}
	}

}

