#11.Write a shell script to find factorial of a given integer.
#!/bin/sh

read -p "Enter a number:" num
i=1
fact=1
while [ $i -le $num ]
do
	fact=$(($fact*$i))
	i=$(($i+1))
done
echo "Factorial=" $fact
