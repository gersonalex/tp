K=gcc
L=-c
listing=3.6
path=/home/alex/Desktop/tp/src/listing$(listing)
path2=/home/alex/Desktop/tp/build/listing$(listing)

main: $(path)/main.o
	$(K) $(path)/main.o -o $(path2)/main
main.o: $(path)/main.c
	$(K) $(L) $(path)/main.c
cleanObjects:
	rm /home/alex/Desktop/tp/src/listing$(listing)/main.o
cleanExecutables:
	rm /home/alex/Desktop/tp/build/listing$(listing)/main

