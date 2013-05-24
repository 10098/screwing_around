#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>

using namespace std;

typedef shared_ptr<istream> fileptr;

void merge_sorted_files(vector<fileptr> &files)
{
   vector<pair<int, fileptr> > h;
   auto cmp = [](const pair<int,fileptr> &a, const pair<int,fileptr> &b) { return a.first > b.first; };

   for(auto f: files) {
      int i;
      if((*f) >> i)
         h.push_back(make_pair(i, f)); 
   }

   make_heap(h.begin(), h.end(), cmp);
   while(h.size()) {
      pop_heap(h.begin(), h.end(), cmp);
      int popped = h.size() - 1;
      cout << h[popped].first << endl;
      if((*h[popped].second) >> h[popped].first)
         make_heap(h.begin(), h.end(), cmp);
      else
         h.pop_back();
   }
}

int main(int argc, char *argv[])
{
   if(argc > 1) {
      vector<fileptr> files;
      for(int i = 1; i < argc; ++i) {
         files.push_back(fileptr(new ifstream(argv[i])));
      }
      merge_sorted_files(files);
   }
   return 0;
}

