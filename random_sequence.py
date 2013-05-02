import random
import sys

def gen_random_sequence(length):
   r = []
   for x in range(0, length):
      r.append(random.randint(0, 1000))
   return r
    
if __name__ == "__main__":
   if len(sys.argv)  > 1:
      print(gen_random_sequence(int(sys.argv[1])))

