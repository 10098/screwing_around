#include "protobuf_test.pb.h"
#include <iostream>

int main()
{
	TestMsg m;
	m.ParseFromIstream(&std::cin);
	std::cout << m.enum_val() << " " << m.int_val() << std::endl;
	return 0;
}
