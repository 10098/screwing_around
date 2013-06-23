#pragma once

#include "tree.h"

template <class T>
void bst_insert(typename TreeNode<T>::Ptr &root, const T &value)
{
	if(root) {
		if(value >= root->value) {
			bst_insert(root->right, value);
		} else {
			bst_insert(root->left, value);
		}
	} else {
		root.reset(new TreeNode<T>(value));
	}
}

