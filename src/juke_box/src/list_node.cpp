#include "list_node.h"
#include <iostream>



namespace jukebox {
ListNode::ListNode(const std::wstring& node_type,
				   const std::set<std::wstring>& list_options,
				   const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				   int num):
	RuleNode{node_type, nodes_container ,num},
	list_options_{list_options}
{

}



std::string ListNode::Handale(const Song& song)
{
	std::string param = song[node_type_];
	std::wstring wsTmp(param.begin(), param.end());
	auto found = list_options_.find(wsTmp);

	//item not found
	//if `false` we move to the right child
	if (found == list_options_.end()) {
		return nodes_container_.at(num_ * 2 + 1)->Handale(song);
	}
	//item found
	//test node evaluates as `true` we move to it's left child
	else {
		return nodes_container_.at(num_ * 2)->Handale(song);
	}
}

}
