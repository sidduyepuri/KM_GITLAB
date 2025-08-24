all:a.out
	echo "Build Done"
a.out:main.c add.c sub.c 
	gcc main.c add.c sub.c -o a.out
clean:
	rm *.o a.out
install:
	sudo cp a.out /bin
