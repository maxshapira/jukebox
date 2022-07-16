#include "file_parser.h"
#include "song.h"

#include <fstream>
#include <iostream>
#include <set>

using namespace std;
using namespace jukebox;


using namespace nlohmann;


int main() {

	std::ifstream songs_file("data/songs.json", std::ifstream::binary);
	json::value_type songs;
	songs_file >> songs;
	Song song{ songs.front() };

	auto wstrs = jukebox::ReadFile("data/mae-j");

	for (auto it = wstrs.begin(); it != wstrs.end();) {
		auto num = *it++;
		auto n_type = *it++;
		bool sucess = false;
		if (n_type == L"Artist") {
			auto begin = it + 1;
			auto end = it + 1 + (*it).front();

			set<wstring> artists(begin, end);
			wstring art(song.artist.begin(), song.artist.end());
			auto artist = artists.find(art);
			if (artist == artists.end()) {
				sucess = false;			}
			else {
				sucess = true;
			}
		}
		if (!sucess) {
			auto b = *(it + 1 + (*it).front() + 1);
			wcout << *(it + 1 + (*it).front() + 1) << endl;
			int a = 0;
		}
	}
}



//// CPP program to construct binary 
//// tree from given array in level
//// order fashion Tree Node
//#include <iostream>
//using namespace std;
//
///* A binary tree node has data,
//pointer to left child and a
//pointer to right child */
//struct Node
//{
//	int data;
//	Node* left, * right;
//};
//
///* Helper function that allocates a
//new node */
//Node* newNode(int data)
//{
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->data = data;
//	node->left = node->right = NULL;
//	return (node);
//}
//
//// Function to insert nodes in level order
//Node* insertLevelOrder(int arr[],
//	int i, int n)
//{
//	Node* root = nullptr;
//	// Base case for recursion
//	if (i < n)
//	{
//		root = newNode(arr[i]);
//
//		// insert left child
//		root->left = insertLevelOrder(arr,
//			2 * i + 1, n);
//
//		// insert right child
//		root->right = insertLevelOrder(arr,
//			2 * i + 2, n);
//	}
//	return root;
//}
//
//
//// Function to insert nodes in level order
//Node* insertLevelOrder1(int arr[],
//	int i, int n)
//{
//	Node* root = nullptr;
//	// Base case for recursion
//	if (i < n)
//	{
//		root = newNode(arr[i]);
//
//		if (arr[i + 1] == arr[i] * 2) {
//			// insert left child
//			root->left = insertLevelOrder(arr, i + 1, n);
//		}
//		else if(arr[i+1] == arr[i] * 2 + 1) {
//			// insert right child
//			root->right = insertLevelOrder1(arr, i+1, n);
//		}
//		else if(arr[i + 2] == arr[i] * 2 + 1) {
//			root->right = insertLevelOrder1(arr, i + 2, n);
//
//		}
//	}
//	return root;
//}
//
//// Function to print tree nodes in
//// InOrder fashion
//void inOrder(Node* root)
//{
//	if (root != NULL)
//	{
//		inOrder(root->left);
//		cout << root->data << " ";
//		inOrder(root->right);
//	}
//}
//
//// Driver program to test above function
//int main()
//{
//	int arr[] = { 1, 2, 3, 6, 7};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	//Node* root = insertLevelOrder(arr, 0, n);
//	Node* root = insertLevelOrder1(arr, 0, n);
//	inOrder(root);
//}
//
//// This code is contributed by Chhavi and improved by Thangaraj
