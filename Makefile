tros: main.o sort.o utils.o
	gcc main.o sort.o utils.o -o tros

main.o: src/main.c
	gcc -c src/main.c

sort.o: src/sort.c
	gcc -c src/sort.c

utils.o: src/utils.c
	gcc -c src/utils.c

clean:
	rm *.o tros

run:
	make; ./tros
