compileAll: que.o multiq.o testMultiQ.o
	gcc que.o multiq.o testMultiQ.o
	./a.out

que.o: que.c que.h
	gcc -c que.c

multiq.o: multiq.c multiq.h que.h
	gcc -c multiq.c
	
testMultiQ.o: testMultiQ.c multiq.h que.h
	gcc -c testMultiQ.c
