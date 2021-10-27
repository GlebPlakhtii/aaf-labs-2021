#include "Rect.h"
#include "R_Tree.h"
#include <vector>
#include <iostream>


using namespace std;



int main()
{
	R_Tree tree = R_Tree();
	tree.incert(Rect(0, 0, 2, 2));
	tree.incert(Rect(1, 1, 4, 3));
	tree.incert(Rect(7, 1, 9, 3));
	tree.incert(Rect(4, 4, 6, 5));
	tree.incert(Rect(2, 4, 3, 8));
	tree.incert(Rect(3, 6, 7, 8));
	tree.incert(Rect(4, 0, 5, 1));
	tree.incert(Rect(9, 5, 11, 6));
	tree.incert(Rect(6, 8, 8, 10));
	tree.incert(Rect(11, 2, 13, 4));
	tree.incert(Rect(11, 6, 13, 8));
	tree.incert(Rect(-1, -1, 0, 0));
	tree.incert(Rect(13, 10, 15, 11));
	tree.incert(Rect(7, 0, 9, 1));
	tree.incert(Rect(8, 3, 9, 4));
	
	tree.print_tree();

	
	
	//tree.dfs();
	
	
	



}


