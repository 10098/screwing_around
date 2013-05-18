#include "protobuf_test.pb.h"
#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
	TestMsg m;
	m.set_enum_val(TestMsg::VAL3);
	m.set_int_val(42);
	std::vector<char> v(m.ByteSize(), 0);
	m.SerializeToOstream(&std::cout);
	m.SerializeToArray(&v[0], v.size());
	getc(stdin);
	return 0;
}
