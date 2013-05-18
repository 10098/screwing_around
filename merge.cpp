#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>

template <class T>
void merge( typename std::vector<T>::iterator begin, typename std::vector<T>::iterator mid, typename std::vector<T>::iterator end)
{ 
   std::vector<T> tmp( end - begin );
   std::copy( begin, end, tmp.begin() );
   auto tmp_l = tmp.begin(), tmp_r = tmp_l + (mid - begin), tmp_m = tmp_r, a = begin;
   while( tmp_l < tmp_m && tmp_r < tmp.end() ) {
      if( *tmp_l < *tmp_r )
         *(a) = *(tmp_l++);
      else
         *(a) = *(tmp_r++);
      a++;
   }
   std::copy(tmp_l, tmp_m, a);
}


template <class T>
void merge_sort( typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
   if(end <= begin || end-begin <= 1) return;
   auto midpoint = begin + ( end - begin ) / 2;
   merge_sort<T>(begin, midpoint);
   merge_sort<T>(midpoint, end);
   merge<T>(begin, midpoint, end);
}

int main(int argc, char *argv[])
{
   std::vector<int> v;
   std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
   clock_t c = clock();
   merge_sort<int>(v.begin(), v.end());
   double time = (clock() - c)/CLOCKS_PER_SEC;
   if(argc >= 2 && argv[1][0] == 'a'){
      std::cout << time << std::endl;
   } else {
      std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
      std::cout << std::endl;
   }
   return 0;
}

