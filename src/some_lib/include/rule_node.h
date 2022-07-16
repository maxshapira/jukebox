#pragma once
#include "node.h"
#include <memory>



namespace jukebox {
	class RuleNode : public Node {
	public:
		RuleNode(const std::wstring& node_type,
				 std::shared_ptr<Node> left,
				 std::shared_ptr<Node> right);

		virtual std::string Handale(const Song& song) override;

	protected:
		std::string NodeTypeToStr(const std::wstring& node_type);

		const std::string node_type_;

		const std::shared_ptr<Node> left_;

		const std::shared_ptr<Node> right_;
	};
}