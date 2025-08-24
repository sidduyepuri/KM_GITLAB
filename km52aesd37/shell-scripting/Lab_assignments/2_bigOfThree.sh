#2. Write Script to find out biggest number from given three nos. Nos are supplied as command line arguments. Print error if sufficient a    rguments are not supplied.
#!/bin/sh

if [ $# -eq 3 ]
then
	big=$1
	if [ $2 -gt $big ]
	then
		big=$2
	fi
	if [ $3 -gt $big ]
	then
		big=$3
	fi
	echo "Biggest:"$big

else
	echo "ERROR"
	echo "please, Enter three numbers for find biggest"
fi


