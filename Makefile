all:
	gcc -fPIC --shared cheat.c -o cheat.so
clean:
	rm cheat.so

