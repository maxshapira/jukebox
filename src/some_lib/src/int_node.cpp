#include "int_node.h"
#include <codecvt>



namespace jukebox {
	IntNode::IntNode(const std::wstring& node_type,
					  int param,
					  std::shared_ptr<Node> left,
					  std::shared_ptr<Node> right):
		RuleNode{node_type, left, right},
		param_{param}
	{

	}



	std::string IntNode::Handale(const Song& song)
	{
		auto param = song[node_type_];

		//test node evaluates as `true` we move to it's left child
		if (param <= param_) {
			return left_->Handale(song);
		}
		//if `false` we move to the right child
		else {
			return right_->Handale(song);
		}
	}

}

