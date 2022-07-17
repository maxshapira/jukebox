#pragma once
#include "rule_node.h"
#include <set>



namespace jukebox {
	//Class that implement the mid or first node in a chain, that decide go to left or to right child by param compare.
	class ListNode : public RuleNode {
	public:
		//Store relevant info.
		ListNode(const std::wstring& node_type,
				 const std::set<std::wstring>& list_options,
				 const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				 int num);

		// Decide go to left or to right child.
		virtual std::string Handale(const Song& song) override;

	private:
		//To compare with song parameter.
		const std::set<std::wstring> list_options_;
	};

}