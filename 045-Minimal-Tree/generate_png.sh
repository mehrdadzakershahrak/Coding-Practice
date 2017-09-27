#!/bin/bash
for t in $(find . -name "test*.txt" -type f | sort); do
    cat $t | ./a.out | dot -Tpng > $t.png
done
