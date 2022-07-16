#include "int_node.h"



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

		if (param <= param_) {
			return right_->Handale(song);
		}
		else {
			return left_->Handale(song);

		}
	}

}

