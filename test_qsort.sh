function rand_seq() {
  for r in `seq 0 $1`
  do
     expr $RANDOM % 1000
  done
}

RSEQ=`rand_seq 10`
SORTED=`sort -n <<EOD
$RSEQ
EOD`
OUTPUT=`./qsort <<EOD
$RSEQ
EOD`
if [ "$SORTED" == "$OUTPUT" ]
then
   echo OK
else
   echo FAIL
   echo "$SORTED"
   echo =======
   echo "$OUTPUT"
   echo ======
fi   
