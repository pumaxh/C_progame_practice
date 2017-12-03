calculate_area.exe: calculate_area.o
	gcc calculate_area.o -Wall -o calculate_area.exe

calculate_area.o: calculate_area.c
	gcc -g -c calculate_area.c

sqrt_root.exe: Square_root.o
	gcc Square_root.o -Wall -lm -o sqrt_root.exe

Square_root.o: Square_root.c
	gcc -g -c Square_root.c


clean:
	rm -f *.o *.exe 
