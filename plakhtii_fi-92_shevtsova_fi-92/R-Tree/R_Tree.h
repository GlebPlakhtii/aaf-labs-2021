#pragma once
#include <list>
#include "Rect.h"

class R_Tree
{
private:
	

	class Node {
	public:
		bool is_leaf;
		bool is_root;
		static int Max_entries;
		static int Min_entries;
		Node* parent;
		list<Node*> childs;
		list<Rect> rect;
		Node(bool is_root, bool is_leaf);

	};

	Node* root;

public:
	R_Tree();
	Node* search(Rect rect);
	void insert(pair<int,int> point);
	Node* choose_leaf();
	void adjust_tree(Node* L);


	



	


};



