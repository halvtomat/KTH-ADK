#!/bin/bash

make clean
make step2

while [ "$?" -eq 0 ]
do
    ./flowgen 6 18 10 > test_auto
    sleep 0.001
    DIFF=$(cmp <(head <(./maxflow < test_auto) -n 3) <(head <(./step2 < test_auto) -n 3))
done
clear
echo ------TEST_AUTO----
cat test_auto
echo ------MAXFLOW------
./maxflow < test_auto
echo ------STEP2--------
./step2 < test_auto