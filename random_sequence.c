#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv)
{
   int l;
   int i;
   srand(time(NULL));
   if(argc > 1) {
      l = atoi(argv[1]);
      for(i = 0; i < l; ++i)
      {
         fprintf(stdout, "%d ", rand() % 1000);
         fflush(stdout);
      }
   }
   return 0;
}
