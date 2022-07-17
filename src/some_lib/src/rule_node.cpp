#include "rule_node.h"
#include <codecvt>
#include <iostream>


namespace jukebox {

	RuleNode::RuleNode(const std::wstring& node_type,
					   const std::unordered_map<int, std::shared_ptr<Node>>& nodes_container,
					   int num) :
		node_type_{ NodeTypeToStr(node_type) },
		nodes_container_{nodes_container},
		num_{num}
	{
	}



	std::string RuleNode::Handale(const Song& song)
	{
		return this->Handale(song);
	}



	std::string RuleNode::NodeTypeToStr(const std::wstring& node_type)
	{
		//setup converter
		using convert_type = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_type, wchar_t> converter;

		//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
		std::string converted_str = converter.to_bytes(node_type);
		
		return converted_str;
	}

}