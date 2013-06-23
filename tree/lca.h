#pragma once

#include "tree.h"
#include <stack>
#include <cassert>

template <class T>
typename TreeNode<T>::Ptr lca(const typename TreeNode<T>::Ptr &n1, const typename TreeNode<T>::Ptr &n2)
{
	assert(n1 && n2);

	std::stack<typename TreeNode<T>::Ptr> s1, s2;
	typename TreeNode<T>::Ptr a1 = n1, a2 = n2, lca;
	do {
		s1.push(a1);
		a1 = a1->parent;
	} while(a1.get());

	do {
		s2.push(a2);
		a2 = a2->parent;
	} while(a2.get());

	while(s1.top().get() == s2.top().get()){
		lca = s1.top();
		s1.pop(); s2.pop();
	}

	return lca;
}
