#3. Write script to print given number in reverse order, for eg. If no is 123 it must print as 321
#!/bin/sh

echo -n "Enter a number:"
sum=0
read num
while [ $num -gt 0 ]
do
	sum=$(($sum*10+$num%10))
	num=$(($num/10))
done
echo "reverse:"$sum

