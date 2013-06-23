#include "bst_insert.h"
#include "tree_walk_inorder.h"
#include <iostream>

using namespace std;

int main()
{
	TreeNode<int>::Ptr root;
	bst_insert<int>(root, 10);
	bst_insert<int>(root, 5);
	bst_insert<int>(root, 15);
	bst_insert<int>(root, 3);
	bst_insert<int>(root, 6);
	bst_insert<int>(root, 11);
	bst_insert<int>(root, 10);
	bst_insert<int>(root, 12);
	bst_insert<int>(root, 11);
	bst_insert<int>(root, 16);
	bst_insert<int>(root, 2);
	bst_insert<int>(root, 1);
	bst_insert<int>(root, 4);
	bst_insert<int>(root, 0);
	bst_insert<int>(root, 18);
	bst_insert<int>(root, 17);
	bst_insert<int>(root, 20);
	bst_insert<int>(root, 19);
	tree_walk_inorder<int>(root, [](const TreeNode<int>::Ptr &n){ cout << n->value << endl; });
	return 0;
}
