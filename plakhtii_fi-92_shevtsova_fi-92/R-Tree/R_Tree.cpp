#include "R_Tree.h"
#include "Rect.h"

using namespace std;


R_Tree::R_Tree()
{
	R_Tree::Node::Max_entries = 5;
	R_Tree::Node::Min_entries = 2;
	root = new Node(true,true);
}





R_Tree::Node::Node(bool is_root, bool is_leaf)
{
	this->is_root = is_root;
	this->is_leaf = is_leaf;
}





