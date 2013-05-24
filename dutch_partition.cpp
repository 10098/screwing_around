#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void dutch_partition(vector<int> &v, int pivot)
{
   cout << "partitioning around " << v[pivot] << endl;
   swap(v[0], v[pivot]);
   int eq_edge = 0, edge = 1;
   for(int i = 1; i < v.size(); ++i)
      if(v[i] <= v[0])
         swap(v[i], v[edge++]);
   swap(v[0], v[edge-1]);
   for(int i = 0; i < edge; ++i)
      if(v[i] < v[edge-1])
         swap(v[i], v[eq_edge++]);
}

int main()
{
   vector<int> v;
   int i;
   cin >> i;
   copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
   dutch_partition(v, i);
   copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
   cout << endl;
   return 0;
}
