#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

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

int main(int argc, char **argv)
{
   std::vector<int> v;
   std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
   clock_t c = clock();
   my_qsort(&v[0], 0, v.size());
   clock_t diff = clock() - c;
   if(argc > 1) {
      std::cout << static_cast<double>(diff)/CLOCKS_PER_SEC;
   } else {
      std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
   }
   std::cout << std::endl;
   return 0;
}
