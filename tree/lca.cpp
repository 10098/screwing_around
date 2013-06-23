#include "tree.h"
#include "parse_tree.h"
#include "lca.h"
#include <iostream>

using namespace std;

int main()
{
	TreeNode<int>::Ptr root = parse_tree("(5 (6 (7 - -) (8 (9 (10 - -) (11 - -)) -)) (1 (2 - (3 - -)) -))");
	cout << (lca<int>(root->left->left, root->left->right->left)) -> value << endl;	
	return 0;
}
