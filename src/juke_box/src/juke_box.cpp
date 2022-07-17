#include "juke_box.h"
#include <codecvt>
#include <fstream>
#include <set>
#include "list_node.h"
#include "terminal_node.h"
#include "int_node.h"


using namespace std;



namespace jukebox {
	JukeBox::JukeBox(const std::string& filename)
	{
		BuildContainer(filename);
	}



	std::string JukeBox::Play(const Song& song)
	{
		//handle all rules one by one according to decisions
		return nodes_container_.at(1)->Handale(song);
	}



	void JukeBox::BuildContainer(const std::string& filename)
	{
		//parse the file with rules
		auto wstrs = ReadFile(filename);

		//run over the rules and insert to container
		for (auto it = wstrs.begin(); it != wstrs.end();) {
			auto num = *it++;

			auto n_type = *it++;
			
			//create node
			auto node = CreateNode(num.front(), n_type, it);

			//insert node to appropriate index in table
			nodes_container_[num.front()] = node;
		}
	}



	std::shared_ptr<jukebox::Node> JukeBox::CreateNode(int num,
													   const std::wstring& n_type,
													   std::vector<wstring>::iterator& it)
	{
		shared_ptr<Node> node;

		//create terminal node
		if (n_type == L"Skip" || n_type == L"Play") {
			node = std::make_shared<TerminalNode>(n_type);
		}
		//create list node
		else if (n_type == L"Artist" || n_type == L"Genre") {
			auto begin = it + 1;

			it = it + 1 + (*it).front();

			auto end = it;

			set<wstring> options_list(begin, end);

			node = std::make_shared<ListNode>(n_type, options_list, nodes_container_, num);
		}
		//create int node
		else if (n_type == L"Length" || n_type == L"BPM") {
			it++;

			int param = (*it).front();

			node = std::make_shared<IntNode>(n_type, param, nodes_container_, num);
		}
		return node;
	}



	std::vector<std::wstring>  JukeBox::ReadFile(const std::string& filename)
	{
		std::wifstream wif(filename);

		wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

		std::wstring part;

		std::vector<std::wstring> parts;

		//split line to words 
		while (std::getline(wif, part, L'\0')) {
			//delete empty strings
			if (part != L"")
				parts.push_back(part);
		}

		return parts;
	}
}
