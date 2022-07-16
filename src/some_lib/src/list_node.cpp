#include "list_node.h"



namespace jukebox {
ListNode::ListNode(const std::wstring& node_type,
				   const std::set<std::wstring>& list_options,
				   std::shared_ptr<Node> left,
				   std::shared_ptr<Node> right):
	RuleNode{node_type, left, right},
	list_options_{list_options}
{

}



std::string ListNode::Handale(const Song& song)
{
	auto param = song[node_type_];

	auto found = list_options_.find(param);

	//item not found
	//if `false` we move to the right child
	if (found == list_options_.end()) {
		return right_->Handale(song);
	}
	//item found
	//test node evaluates as `true` we move to it's left child
	else {
		return left_->Handale(song);
	}
}

}
