function run(){
RUNS=$1
SIZE=$2
TOTAL=0
for x in `seq 0 $RUNS`
do
   TIME=`./rseq $SIZE | $3 a`
   TOTAL=`python -c "print($TOTAL+$TIME)"`
done
python -c "print($TOTAL/$RUNS)"
}

for s in `seq 100000 100000 4000000`
do
   echo $s `run 10 $s "$1"`
done
