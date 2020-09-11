#!/bin/bash
#
#This 
export LC_COLLATE=C
make seek
start=`date +%s%N`
./seek hej > result
echo Time =  $((($(date +%s%N) - $start)/1000000)) milliseconds