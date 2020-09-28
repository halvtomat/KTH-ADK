#!/bin/bash
#
#
export LC_COLLATE=C
make seek
start=`date +%s%N`
./seek komplexiteten > result
echo Time =  $((($(date +%s%N) - $start)/1000000)) milliseconds