people : main.c manager.o
	gcc -o people main.c manager.o
manager.o: manager.c manager.h
	gcc -c manager.c -o manager.o
clean :
	rm *.o people
