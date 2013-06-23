#include "tree_walk_inorder.h"
#include "parse_tree.h"
#include <iostream>

using namespace std;

int main()
{
	TreeNode<int>::Ptr r = parse_tree("(5 (3 (2 - -) (4 - -)) (8 (6 - (7 - -)) (9 - (10 - -))))");
	tree_walk_inorder<int>(r, [](const TreeNode<int>::Ptr &n){ cout << n->value << endl; });
	return 0;
}
