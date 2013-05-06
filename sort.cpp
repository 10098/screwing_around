#include <algorithm>
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

void std_qsort(int array[], int left, int right)
{
   std::sort(array + left, array + right); 
}

inline int left(int i)
{
   return 2*i+1;
}

inline int right(int i)
{
   return 2*i+2;
}

inline void my_swp(int *a, int *b)
{
   *a = (*a)^(*b);
   *b = (*a)^(*b);
   *a = (*a)^(*b);
}

void sift_down(int heap[], int root_idx, int heap_size)
{
   if(root_idx >= heap_size/2)
      return;
   int left_idx = left(root_idx), right_idx = right(root_idx);
   int largest_idx = root_idx;
   if(left_idx < heap_size && heap[left_idx] > heap[root_idx])
      largest_idx = left_idx;
   if(right_idx < heap_size && heap[right_idx] > heap[largest_idx])
      largest_idx = right_idx;
   if(largest_idx != root_idx){
      my_swp(&heap[largest_idx], &heap[root_idx]);
      sift_down(heap, largest_idx, heap_size);
   }
}

void build_heap(int array[], int size)
{
   for(int i = size/2; i >= 0; --i) {
      sift_down(array, i, size);
   }
}

void heap_sort(int array[], int size)
{
   build_heap(array, size);
   /*std::copy(array, array+size, std::ostream_iterator<int>(std::cout, " "));
   std::cout << "====\n";*/
   for(int i  = size-1; i > 0; --i){
      my_swp(&array[0], &array[i]);
      sift_down(array, 0, --size);
   }
}

int main(int argc, char **argv)
{
   std::vector<int> v;
   char s;
   if(argc > 1)
      s = argv[1][0];
   else
      s = 'm';

   std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
   clock_t c = clock();
   switch(s){
   case 'q':
      std_qsort(&v[0], 0, v.size());
      break;
   case 'h':
      heap_sort(&v[0], v.size());
      break;
   defualt: 
      my_qsort(&v[0], 0, v.size());
   }
   clock_t diff = clock() - c;
   if(argc > 2) {
      std::cout << static_cast<double>(diff)/CLOCKS_PER_SEC;
   } else {
      std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
   }
   std::cout << std::endl;
   return 0;
}
