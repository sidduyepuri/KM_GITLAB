#6. Write a shell script that accepts a file name, starting and ending line numbers as arguments and displays all the lines between the given line numbers.
#!/bin/sh

read -p "Enter file name:" filename
read -p "Enter starting line:" line1
read -p "Enter ending line:" line2

sed -n "$line1,$line2"p $filename
