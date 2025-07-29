flags = -D _DEBUG -ggdb3 -std=c++17 -O3 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations \
-Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts \
-Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal \
-Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self \
-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 \
-Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override \
-Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast \
-Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast \
-Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow \
-flto-odr-type-merging -fno-omit-frame-pointer -Wstack-usage=8192 -pie -fPIE -Werror=vla \
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

#-------------------------------------------------------------------------------------------------------#

all: sort clean

#compile:

sort: main.o processing_text.o comparators.o utilits.o bubblesort.o
	g++ main.o processing_text.o comparators.o utilits.o bubblesort.o $(flags) -o main

main.o: main.c
	g++ -c $(flags) main.c

processing_text.o: processing_text.c
	g++ -c $(flags) processing_text.c

comparators.o: comparators.c
	g++ -c $(flags) comparators.c

utilits.o: utilits.c
	g++ -c $(flags) utilits.c

bubblesort.o: bubblesort.c
	g++ -c $(flags) bubblesort.c

#run:

length_up:
	./main unsort.txt sort.txt length_up

length_down:
	./main unsort.txt sort.txt length_down

alphabet:
	./main unsort.txt sort.txt alphabet

alphabet_reverse:
	./main unsort.txt sort.txt alphabet_reverse

#clean:

clean:
	rm -rf *.o *.exe *.exe.log *.exe.log.dmp
