#pragma once
#include "node.h"
#include <memory>



namespace jukebox {
	class RuleNode : public Node {
	public:
		RuleNode(const std::wstring& node_type,
				 const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
				 int num);

		virtual std::string Handale(const Song& song) override;

	protected:
		std::string NodeTypeToStr(const std::wstring& node_type);

		const std::string node_type_;

		const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container_;

		int num_;
	};
}