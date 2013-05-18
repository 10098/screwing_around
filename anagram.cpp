#include <iostream>
#include <string>
#include <algorithm>

bool is_anagram(const std::string &a, const std::string &b)
{
   int cc[256] = {0};
   for(char c: a)
      cc[c]++;
   for(char c: b)
      cc[c]--;
   return std::accumulate(cc, cc + sizeof(cc)/sizeof(int), 0) == 0;
}

int main()
{
   std::string a, b;
   std::cin >> a >> b;
   std::cout << is_anagram(a, b) << std::endl;
   return 0;
}
