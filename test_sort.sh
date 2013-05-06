
RSEQ=`./rseq $RAND%100`
SORTED=`sort -n <<EOD
$RSEQ
EOD`
OUTPUT=`./$1 <<EOD
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
