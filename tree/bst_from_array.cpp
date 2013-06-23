#include "tree.h"
#include "bst_insert.h"
#include "tree_walk_inorder.h"
#include <iostream>

using namespace std;

TreeNode<int>::Ptr bst_from_array(int a[], int start, int end)
{
	if(end < start) 		return TreeNode<int>::Ptr();
	else {
		int m = (start+end)/2;
		TreeNode<int>::Ptr r(new TreeNode<int>(a[m]));
		r->left = bst_from_array(a, start, m-1);
		r->right = bst_from_array(a, m+1, end);
		return r;
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 7, 10, 20, 40, 67, 89, 100, 102, 220, 400, 1000, 10000, 10098};
	TreeNode<int>::Ptr r = bst_from_array(a, 0, sizeof(a)/sizeof(int)-1);
	tree_walk_inorder<int>(r, [](const TreeNode<int>::Ptr &n){ cout << n->value << endl; });
	return 0;
}

