pro2.exe:
	g++ -c *.cpp -D_GLIBCXX_DEBUG 
	g++ -o pro2.exe *.o

clean:
	rm -f *.o
	rm -f *.exe