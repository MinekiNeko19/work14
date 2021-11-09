all:
	gcc -o forever signalloop.c
run:
	./forever