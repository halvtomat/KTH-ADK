#!/bin/bash

make clean
make step3

while [ "$?" -eq 0 ]
do
    ./bipgen 10 10 20 > test_auto
    DIFF=$(cmp <(head <(./matchtest< test_auto) -n 2) <(head <(./step3 < test_auto) -n 2))
done
clear
echo ------TEST_AUTO----
cat test_auto
echo ------MAXFLOW------
./matchtest < test_auto
echo ------STEP2--------
./step3 < test_auto