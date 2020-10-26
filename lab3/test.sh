#!/bin/bash

DIFF=$(cmp <(head ut1 -n 3) <(head ut2 -n 3))
COUNT=0

while [ "$?" -eq 0 ]
do
echo $DIFF
    ./flowgen 6 18 10 > test_auto
    sleep 0.001
    DIFF=$(cmp <(head <(./maxflow < test_auto) -n 3) <(head <(./a.out < test_auto) -n 3))
done
