.c.o:	# サフィックスルール。拡張子 .c から拡張子 .o のファイルを作るためのルール。
	cc -c $<

ppm_dump.o: ppm_dump.c kadai5.h
	cc -c ppm_dump.c kadai5.h

ppm_dump: ppm_dump.o 5b.o 5c.o 5e.o 5f.o
	cc -o ppm_dump ppm_dump.o 5b.o 5c.o 5e.o 5f.o

runb: ppm_dump
	./ppm_dump color4x4_binary.ppm

runa: ppm_dump
	./ppm_dump color4x4_ascii.ppm


clean:
	rm -f *.o
