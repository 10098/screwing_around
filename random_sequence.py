import random
import sys

if len(sys.argv)  > 1:
   length = int(sys.argv[1])

   for x in range(0, length):
      print(random.randint(0, 1000), " ", end="")
   print()

