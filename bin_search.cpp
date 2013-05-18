#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int bs(int a[], int begin, int end, int v)
{
   if(end <= begin || end-begin <= 1)
      return -1;
   int m = (begin + end)/2;
   if(v == a[m])
      return m;
   else if(v < a[m])
      return bs(a, begin, m, v);
   else 
      return bs(a, m, end, v);
}

int main()
{
   vector<int> v;
   int k;
   cin >> k;
   copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
   cout << bs(&v[0], 0, v.size(), k) << "\n";
   return 0;
}

