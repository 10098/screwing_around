#include "bst_insert.h"
#include "bst_search.h"
#include "tree_walk_inorder.h"
#include <iostream>
#include <cassert>

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
	TreeNode<int>::Ptr f1, f2;
	f1 = bst_search<int>(root, 100);
	assert(!f1);
	f2 = bst_search<int>(root, 18);
	assert(f2);
	cout << f2->value << endl;
	//tree_walk_inorder<int>(root, [](const TreeNode<int>::Ptr &n){ cout << n->value << endl; });
	return 0;
}
