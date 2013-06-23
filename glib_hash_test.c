#include <glib.h>
#include <stdio.h>

GHashTable *h;
char val[]  = {'H', 'E', 'L', 'L', 'O',0};

void foo()
{
   int k = 10;
   //scanf("%d", &k);
	g_hash_table_insert(h, &k, val);
}

void poo()
{
   int m = 10;
   foo();
   //scanf("%d", &m);
   gpointer *p = g_hash_table_lookup(h, &m);
	printf("%s\n", (const char*)p);
}

int main()
{
	h = g_hash_table_new(g_int_hash, g_int_equal);// NULL, NULL);
	poo();
   return 0;
}
