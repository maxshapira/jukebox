#include "nodes_container.h"
#include <codecvt>
#include <fstream>
#include <set>
#include "list_node.h"
#include "terminal_node.h"
#include "int_node.h"


using namespace std;



namespace jukebox {
	NodesContainer::NodesContainer(const std::string& filename):
		nodes_container_{ Container(filename)}
	{

	}



	std::unordered_map<int, std::shared_ptr<Node>> NodesContainer::Container(const std::string& filename)
	{
		std::unordered_map<int, shared_ptr<Node>> nodes_map;

		auto wstrs = ReadFile(filename);

		for (auto it = wstrs.begin(); it != wstrs.end();) {
			auto num = *it++;

			auto n_type = *it++;

			shared_ptr<Node> node;

			if (n_type == L"Artist" || n_type == L"Genre") {
				auto begin = it + 1;

				it = it + 1 + (*it).front();

				auto end = it;

				set<wstring> options_list(begin, end);

				auto left = nodes_map[num.front() * 2] = nullptr;

				auto right = nodes_map[num.front() * 2 + 1] = nullptr;

				node = std::make_shared<ListNode>(n_type, options_list, left, right);
			}

			else if (n_type == L"Length" || n_type == L"BPM") {
				it++;

				int param = (*it).front();

				auto left = nodes_map[num.front() * 2] = nullptr;

				auto right = nodes_map[num.front() * 2 + 1] = nullptr;

				node = std::make_shared<IntNode>(n_type, param, left, right);
			}
			else if (n_type == L"Skip" || n_type == L"Play") {
				node = std::make_shared<TerminalNode>(n_type);
			}

			nodes_map[num.front()] = node;
		}

		return nodes_map;
	}



	std::vector<std::wstring>  NodesContainer::ReadFile(const std::string& filename)
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
