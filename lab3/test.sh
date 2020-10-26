#!/bin/bash

DIFF=$(cmp <(head ut1 -n 3) <(head ut2 -n 3))
COUNT=0

while [ "$?" -eq 0 ]
do
echo $DIFF
    ./flowgen 6 18 1 > test_auto
    ./maxflow < test_auto > ut1
    ./a.out < test_auto > ut2
    sleep 0.5
    DIFF=$(cmp <(head ut1 -n 3) <(head ut2 -n 3))
done
