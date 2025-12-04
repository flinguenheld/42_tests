#!/usr/bin/env bash

echo "Just a simple line" > "simple_line.txt"
echo -n "Just a simple line without new line" > "simple_line_no_nl.txt"

echo -n "" > "empty.txt"
echo -ne "\n" > "one_new_line.txt"
echo -ne "\t" > "one_tab.txt"
echo -ne "\n\n\n\n\n\n\n\n\n\n" > "ten_new_lines.txt"
echo -ne "\n\n\n\n\npouet\n\n\n\n\n" > "ten_new_lines_with_txt_in_the_middle.txt"

# #############################################################################
echo "0" > "twenty_lines_one_char.txt"
for ((i=1; i<20; i++)); do
  echo "${i:(-1)}" >> "twenty_lines_one_char.txt"
done

# #############################################################################
echo "multiple lines 0" > "multiple_lines.txt"
for ((i=1; i<8; i++)); do
  echo "multiple lines $i" >> "multiple_lines.txt"
done

# #############################################################################
echo "multiple no last nl 0" > "multiple_lines_no_last_nl.txt"
for ((i=1; i<8; i++)); do
  echo "multiple no last nl $i" >> "multiple_lines_no_last_nl.txt"
done
echo -n "multiple no last nl last" > "multiple_lines_no_last_nl.txt"

# #############################################################################
rm "multiple_long_lines.txt" 2> /dev/null
touch "multiple_long_lines.txt"
for ((i=1; i<8; i++)); do
  echo -n "multiple long line $i -> " >> "multiple_long_lines.txt"
  for ((j=1; j<1000; j++)); do
    echo -n "$i" >> "multiple_long_lines.txt"
  done
  echo " end of line $i" >> "multiple_long_lines.txt"
done

# #############################################################################
echo "a" > "long_unique_line.txt"
for ((i=1; i<99999; i++)); do
  echo -n "b" >> "long_unique_line.txt"
done
  echo "c" >> "long_unique_line.txt"

# #############################################################################
echo "i" > "long_unique_line_no_nl.txt"
for ((i=1; i<99999; i++)); do
  echo -n "j" >> "long_unique_line_no_nl.txt"
done
  echo -n "k" >> "long_unique_line_no_nl.txt"

# #############################################################################
echo "line 0" > "lot_of_lines.txt"
for ((i=1; i<100000; i++)); do
  echo "line $i" >> "lot_of_lines.txt"
done

# #############################################################################
echo "line 0" > "lot_of_lines_no_last_nl.txt"
for ((i=1; i<99999; i++)); do
  echo "line $i" >> "lot_of_lines_no_last_nl.txt"
done
  echo -n "line last without nl" >> "lot_of_lines_no_last_nl.txt"

# #############################################################################
# ################################################################### BONUS ###
# #############################################################################

echo "Text from file 1" > "bonus_simple_file_1.txt"
echo "Text from file 2" > "bonus_simple_file_2.txt"
echo "Text from file 3" > "bonus_simple_file_3.txt"

# #############################################################################
echo -n "" > "bonus_empty_file_1.txt"
echo -n "" > "bonus_empty_file_2.txt"
echo -n "" > "bonus_empty_file_3.txt"

# #############################################################################
for ((i=1; i<=10; i++)); do
  rm "bonus_10_lines_file_$i.txt" 2> /dev/null
  touch "bonus_10_lines_file_$i.txt"
  echo "Hello, line 0 from file $i" >> "bonus_10_lines_file_$i.txt"
  for ((j=1; j<10; j++)); do
    echo "Hello, line $j from file $i" >> "bonus_10_lines_file_$i.txt"
  done
done

# #############################################################################
for ((i=1; i<=10; i++)); do
  rm "bonus_10_long_lines_file_$i.txt" 2> /dev/null
  touch "bonus_10_long_lines_file_$i.txt"
  for ((j=1; j<10; j++)); do
    echo "new line in file $i" >> "bonus_10_long_lines_file_$i.txt"
    for ((k=1; k<10; k++)); do
      echo -n "$RANDOM%20000" | sha256sum | tr '\n' 'A'  >> "bonus_10_long_lines_file_$i.txt"
    done
  done
  echo -ne "\nEND OF FILE WITHOUT NEW LINE !" >> "bonus_10_long_lines_file_$i.txt"
done
