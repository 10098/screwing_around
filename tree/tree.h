#pragma once

#include <memory>

template <class T>
struct TreeNode
{
	typedef std::shared_ptr<TreeNode> Ptr;

	TreeNode(){}

	TreeNode(const T &val) : value(val) {}

	T value;
	Ptr left;
	Ptr right;
	Ptr parent;
};

