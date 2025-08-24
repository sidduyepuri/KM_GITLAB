#4. Write script to determine whether given file exist or not, file name is supplied as command line argument, Also check for sufficient     number of command line arguments.

#!/bin/sh

test -e $1
if [ $? = 0 ]
then
	echo "File is Exist"
else
	echo "File doesn't exist"
fi
