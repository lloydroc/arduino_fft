# We will build the fft and
# run main which has test cases
all:
	gcc -c fft.c -o fft.o
	gcc -c main.c -o main.o
	gcc fft.o main.o -o fft
	./fft

clean:
	rm *.o fft
