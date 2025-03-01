sysLib=-lsfml-graphics -lsfml-window -lsfml-system
SO=-shared -fPIC
source=$(wildcard *.cpp)
file=$(patsubst %.cpp,%,${source})
libName=\
				lib/bin/libupdate.so\
				lib/bin/libmyPlug.so
test:test.cpp ${libName}
	g++ test.cpp ${libName} -o test ${usrLib} ${sysLib} -L.

lib/bin/update.o:lib/core/update.cpp
	g++ $^ -c -o $@

lib/bin/libupdate.so:lib/bin/update.o
	g++ $^ -o $@ ${SO}

lib/bin/myPlug.o:lib/plug/myPlug.cpp
	g++ $^ -c -o $@

lib/bin/libmyPlug.so:lib/bin/myPlug.o
	g++ $^ -o $@ ${SO}

clean:
	rm ${file} lib/bin/*
