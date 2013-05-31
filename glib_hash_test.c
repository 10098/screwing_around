#include <glib.h>
#include <stdio.h>

int main()
{
	GHashTable *h = g_hash_table_new(g_int_hash, g_int_equal);
	int k1 = 10, k2 = 10;
	char val[]  = {'H', 'E', 'L', 'L', 'O'};
	g_hash_table_insert(h, &k1, val);
	printf("%s\n", (const char*)g_hash_table_lookup(h, &k2));
	return 0;
}
