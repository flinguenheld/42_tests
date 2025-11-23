#!/bin/bash

echo -n '' > empty.txt
echo -n '0123456789' > 10_without_nl.txt
echo '0123456789' > 10_with_nl.txt

echo '' > lot_of_lines.txt
echo '' > long_line.txt
for i in {1..20000}; do
    echo "line $i" >> lot_of_lines.txt
    echo -n " $i " >> long_line.txt
done

