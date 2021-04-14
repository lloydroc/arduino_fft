# We will build the fft and
# run main which has test cases
all:
	gcc -g -O0 -Wall -Werror -c fft.c -o fft.o
	gcc -g -O0 -Wall -Werror -c main.c -o main.o
	gcc -g -O0 -Wall -Werror -lm fft.o main.o -o fft
	./fft

clean:
	rm *.o fft
