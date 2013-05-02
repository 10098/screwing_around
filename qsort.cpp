#include <iostream>
#include <vector>
#include <iterator>

int partition(int a[], int left, int right)
{
   int pivot_value = a[left];
   int j = left;
   
   for(int i = left + 1; i < right; ++i) {
      if(a[i] < pivot_value ) {
         ++j;
         std::swap(a[i], a[j]);
      }
   }
   std::swap(a[j], a[left]);
   return j;
}

void my_qsort(int array[], int left, int right)
{
   if(right - left > 1) {
      int pivot_idx = partition(array, left, right);
      my_qsort(array, left, pivot_idx);
      my_qsort(array, pivot_idx + 1, right);
   }
}

int main()
{
   std::vector<int> v;
   std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
   my_qsort(&v[0], 0, v.size());
   std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
   std::cout << std::endl;
   return 0;
}
