#1. Write shell script that will add two nos, which are supplied as command line argument, and if this two nos are not given show error a    nd its usage
#!/bin/sh

if [ $# -eq 2  ]
then
	echo "add:"$(($1+$2))
else
	echo "ERROR"
	echo "please, Enter two numbers for addition"
fi

