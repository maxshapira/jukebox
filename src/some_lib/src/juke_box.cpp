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
		Container(filename);
	}



	std::string JukeBox::Play(const Song& song)
	{
		return nodes_container_.at(1)->Handale(song);
	}



	void JukeBox::Container(const std::string& filename)
	{
		auto wstrs = ReadFile(filename);

		for (auto it = wstrs.begin(); it != wstrs.end();) {
			auto num = *it++;

			auto n_type = *it++;

			auto node = CreateNode(num.front(), n_type, it);

			nodes_container_[num.front()] = node;
		}
	}



	std::shared_ptr<jukebox::Node> JukeBox::CreateNode(int num,
													   const std::wstring& n_type,
													   std::vector<wstring>::iterator& it)
	{
		shared_ptr<Node> node;

		if (n_type == L"Skip" || n_type == L"Play") {
			node = std::make_shared<TerminalNode>(n_type);
		}
		else {
			//auto& left = nodes_container_[num * 2] = nullptr;

			//auto& right = nodes_container_[num * 2 + 1] = nullptr;

			if (n_type == L"Artist" || n_type == L"Genre") {
				auto begin = it + 1;

				it = it + 1 + (*it).front();

				auto end = it;

				set<wstring> options_list(begin, end);

				node = std::make_shared<ListNode>(n_type, options_list, nodes_container_, num);
			}
			else if (n_type == L"Length" || n_type == L"BPM") {
				it++;

				int param = (*it).front();

				node = std::make_shared<IntNode>(n_type, param, nodes_container_, num);
			}
		}
		return node;
	}



	std::vector<std::wstring>  JukeBox::ReadFile(const std::string& filename)
	{
		std::wifstream wif(filename);

		wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

		std::wstring part;

		std::vector<std::wstring> parts;

		while (std::getline(wif, part, L'\0')) {
			if (part != L"")
				parts.push_back(part);
		}

		return parts;
	}
}
