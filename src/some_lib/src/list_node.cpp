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
	if (found == list_options_.end()) {
		return left_->Handale(song);
	}
	//item found
	else {
		return right_->Handale(song);
	}
}

}
