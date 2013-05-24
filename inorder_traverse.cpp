#include <iostream>

using namespace std;

struct node
{
   char data;
   node *left;
   node *right;
   node *parent;
};

void traverse(node *r)
{
   node *cur = r, *prev = 0;
   while(cur) {
      if(prev == cur->left) {
         cout << cur->data << " ";
         if(cur->right) cur = cur->right;
         else { prev = cur; cur = cur->parent; }
      } else if(prev == cur->right) {
         prev=cur;
         cur = cur->parent;
      } else if(cur->left) cur = cur->left;
      else prev = cur->left;
   }
}

int main()
{
   node *l1 = new node({'1',0,0,0});
   node *l2 = new node({'2',0,0,0});
   node *a=new node({'a',l1,l2,0});
   l1->parent = l2->parent = a;
   node *b=new node({'b',0,0,0});
   node *r=new node({'r',a,b,0});
   b->parent = a->parent = r;
   traverse(r);
   cout << "\n";
   return 0;
}
