#include "Rect.h"
#include "R_Tree.h"
#include <vector>
#include <iostream>



using namespace std;



int main()
{
	R_Tree tree = R_Tree();
	for(int i = 0; i<30 ; i++){
        tree.incert(Rect(i,i,i+1,i+1));
    }

	tree.print_tree();
    cout<<tree.to_string()<<endl;







}



