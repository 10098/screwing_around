function run(){
RUNS=$1
SIZE=$2
TOTAL=0
for x in `seq 0 $RUNS`
do
   TIME=`./rseq $SIZE | ./qsort a`
   TOTAL=`python -c "print($TOTAL+$TIME)"`
done
python -c "print($TOTAL/$RUNS)"
}

for s in `seq 100000 100000 2000000`
do
   echo $s `run 10 $s`
done
