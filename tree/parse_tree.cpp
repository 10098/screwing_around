#include "parse_tree.h"
#include <cctype>
#include <stdexcept>
#include <sstream>

void read_bracket(const std::string &data, char bracket_char, size_t &pos)
{
	while(pos < data.length() && isspace(data[pos])) pos++;
	if(pos == data.length() || data[pos++] != bracket_char) throw std::runtime_error("expected bracket");
}

bool is_empty(const std::string &data, size_t &pos)
{
	while(pos < data.length() && isspace(data[pos])) pos++;
	if(pos < data.length()) {
		if(data[pos] == '-') {
			pos++;
			return true;
		} else {
			return false;
		}
	}
	else throw std::runtime_error("unexpected end of input");
}

int read_int(const std::string &data, size_t &pos)
{
	while(pos < data.length() && isspace(data[pos])) pos++;
	if(pos == data.length() || !isdigit(data[pos])) throw std::runtime_error("expected digit");
	size_t num_start = pos;
	size_t num_len = 0;
	while(pos < data.length() && isdigit(data[pos++])) num_len++;
	std::istringstream is(data.substr(num_start, num_len));
	int val;
	is >> val;
	return val;
}

TreeNode<int>::Ptr parse_tree_helper(const std::string &data, size_t &pos)
{

	TreeNode<int>::Ptr p;
	if(is_empty(data, pos))
	{
		return p;
	} 
	else
	{
		p.reset(new TreeNode<int>());
		read_bracket(data, '(', pos);
		p->value = read_int(data, pos);
		p->left = parse_tree_helper(data, pos);
		if(p->left) p->left->parent = p;
		p->right = parse_tree_helper(data, pos);
		if(p->right) p->right->parent = p;
		read_bracket(data, ')', pos);
	}
	return p;
}

TreeNode<int>::Ptr parse_tree(const std::string &data)
{
	size_t pos = 0;
	return parse_tree_helper(data, pos);
}

