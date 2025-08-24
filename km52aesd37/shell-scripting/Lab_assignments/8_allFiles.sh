#8. Write a shell script that displays a list of all the files in the current directory to which the user has read, write and execute permissions.
#!/bin/sh
echo "In current directory, these files having read,write and excecute permissions:"
for i in *
do
	if  [ -f "$i" ]&&[ -r "$i" ]&&[ -w "$i" ]&&[ -x "$i" ]
	then
		echo $i
	fi
done

