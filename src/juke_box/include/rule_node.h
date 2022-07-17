#pragma once
#include "node.h"
#include <memory>



namespace jukebox {
	
	// The default rule node behavior implemented here.
	class RuleNode : public Node {
	public:
		//store params
		RuleNode(const std::wstring& node_type,
				 const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				 int num);

		virtual std::string Handale(const Song& song) override;

	protected:
		const std::string node_type_;

		//to know where continue(left, right childes)
		const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container_;

		//node index
		int num_;
	};
}