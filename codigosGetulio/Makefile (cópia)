
PROG=primosconcorrentes

exec: 
	./${PROG}.exe 100 200
	
run: compilar
	./${PROG}.exe 100 200

compilar: clean
	gcc ${PROG}.c -o ${PROG}.exe -lpthread

clean:
	rm -f *.exe

zip:
	tar -czvf `(date +%y-%m-%d-%H-%M-%S)`.tar.gz Makefile ${PROG}.c


