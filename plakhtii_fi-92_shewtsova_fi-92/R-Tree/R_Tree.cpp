#include "R_Tree.h"
#include <list>

using namespace std;


R_Tree::R_Tree(int t)
{
	this->t = t;
	Node root;

}



R_Tree::Node::Node()
{
	list<Node*> pointers;
	list<pair<pair<int,int>,pair<int,int>>> rect;
}

void Set_t(int t)
{
	
	Node::T = t;
	Node::Max_entries = 2 * T - 1;
	Node::Min_entries = T - 1;

	
}
