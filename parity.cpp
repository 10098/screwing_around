#include <iostream>
#include <iterator>
#include <vector>
#include <stdint.h>

using namespace std;

int parity(const vector<uint64_t> &v)
{
   int parity = 0;
   for(uint64_t x: v) {
      while(x) {
         parity ^= 1;
         x &= (x-1);
      }
   }
   return parity;
}

int main()
{
   vector<uint64_t> v;
   copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
   cout << parity(v) << endl;
   return 0;
}
