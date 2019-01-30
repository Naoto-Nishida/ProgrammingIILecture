counter: counter_main.o counter.o
	cc -o counter counter_main.o counter.o
.c.o:	# サフィックスルール。拡張子 .c から拡張子 .o のファイルを作るためのルール。
	cc -c $<
counter_main.o: counter.h
