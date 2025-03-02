sysLib=-lsfml-graphics -lsfml-window -lsfml-system
SO=-shared -fPIC
source=$(wildcard *.cpp)
flag=-O3
file=$(patsubst %.cpp,%,${source})
libName=\
				lib/bin/libupdate.so\
				lib/bin/libmyPlug.so
test:test.cpp ${libName}
	g++ test.cpp ${libName} ${flag} -o test ${usrLib} ${sysLib} -L.

lib/bin/update.o:lib/core/update.cpp
	g++ $^ -c ${flag} -o $@

lib/bin/libupdate.so:lib/bin/update.o
	g++ $^ ${flag} -o $@ ${SO}

lib/bin/myPlug.o:lib/plug/myPlug.cpp
	g++ $^ ${flag} -c -o $@

lib/bin/libmyPlug.so:lib/bin/myPlug.o
	g++ $^ ${flag} -o $@ ${SO}

clean:
	rm ${file} lib/bin/*
