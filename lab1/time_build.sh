#!/bin/bash
#
#This 
export LC_COLLATE=C
make clean
make
start=`date +%s`
./tokenizer < korpus | ./main > result
end=`date +%s`
echo Time = `expr $end - $start` seconds