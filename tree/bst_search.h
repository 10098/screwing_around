#pragma once 

#include "tree.h"

template <class T>
typename TreeNode<T>::Ptr bst_search(const typename TreeNode<T>::Ptr &root, const T &data)
{
	if(root) {
		if(data == root->value) 
			return root;
		else if(data > root->value)
			return bst_search(root->right, data);
		else
			return bst_search(root->left, data);
	} else {
		return typename TreeNode<T>::Ptr();
	}
}
