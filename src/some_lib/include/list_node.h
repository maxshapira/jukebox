#pragma once
#include "rule_node.h"
#include <set>



namespace jukebox {
	class ListNode : public RuleNode {
	public:
		ListNode(const std::wstring& node_type,
				 const std::set<std::wstring>& list_options,
				 const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				 int num);

		virtual std::string Handale(const Song& song) override;

	private:
		const std::set<std::wstring> list_options_;
	};

}