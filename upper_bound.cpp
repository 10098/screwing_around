#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int upper_bound(int a[], int size, int k)
{
   int l = 0, u = size - 1, mid;
   while(l <= u) {
      mid = l + (u - l) / 2;
      int v = a[mid];
      if(v > k && (mid == 0 || a[mid - 1] <= k))
         return mid;
      else if(v > k)
         u = mid - 1;
      else // v <= k
         l = mid + 1;
   }
   return size;
}

int main()
{
   vector<int> v;
   int k;
   cin >> k;
   copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
   cout << upper_bound(&v[0], v.size(), k) << " " << (upper_bound(v.begin(), v.end(), k) - v.begin()) << endl;
   return 0;
}
