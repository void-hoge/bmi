PROGRAM	= bmi
CC	= gcc
OPTIM	= -O3 -mtune=native -march=native -flto
STD	=
FLAGS	= -lm

$(PROGRAM): main.c
	$(CC) main.c $(OPTIM) $(FLAGS) $(STD) -o $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) -h
	./$(PROGRAM) 1.66 57
	./$(PROGRAM) 166

clean:
	rm bmi | rm *.out | rm *.o
