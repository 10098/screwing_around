#include "queue.h"
#include <iostream>
using namespace std;
int main()
{
	Queue q;
	for(int i = 0; i <= 20; ++i)
	{
		q.push(i);
		if(i == 5) {
			while(q.top() != 3) q.pop();
		}
	}
	while(q.count()) cout << q.pop() << endl;
	return 0;
}
