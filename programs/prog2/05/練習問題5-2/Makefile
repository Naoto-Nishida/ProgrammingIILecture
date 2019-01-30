sort_int: main.o my_util.o
	cc -o sort_int main.o my_util.o
main.o: main.c
	cc -c main.c
my_util.o: my_util.c
	cc -c my_util.c

#.c.o:	# サフィックスルール。拡張子 .c から拡張子 .o のファイルを作るためのルール。
#	cc -c $<

clean:
	rm -f *.o

run: sort_int
	./sort_int
