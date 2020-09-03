#!/bin/bash
#
#This 

make clean
make
start=`date +%s`
./tokenizer < korpus | ./main > result
end=`date +%s`
echo Time = `expr $end - $start` seconds