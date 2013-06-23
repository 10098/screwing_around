#pragma once

#include "tree.h"
#include <functional>

template <class T, class CallbackType>
void tree_walk_inorder(const typename TreeNode<T>::Ptr &root, const CallbackType &visit_callback)
{
	if(root.get()) {
		tree_walk_inorder<T>(root->left, visit_callback);
		visit_callback(root);
		tree_walk_inorder<T>(root->right, visit_callback);
	}
}

