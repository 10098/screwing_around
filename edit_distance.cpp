#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int min3(int a, int b, int c)
{
   return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int edit_distance(const string &a, const string &b)
{
   vector<vector<int> > t(a.size() + 1, vector<int>(b.size() + 1));
   for(int i = 0; i <= a.size(); ++i) t[i][0] = i;
   for(int j = 0; j <= b.size(); ++j) t[0][j] = j;
   for(int i = 1; i <= a.size(); ++i)
      for(int j = 1; j <= b.size(); ++j)
         t[i][j] = (a[i-1] == b[j-1]) ? t[i-1][j-1] : (1+min3(t[i-1][j-1], t[i][j-1], t[i-1][j]));
   return t[a.size()][b.size()]; 
}

int main()
{
   string a, b;
   cin >> a >> b;
   cout << edit_distance(a, b);
   return 0;
}

