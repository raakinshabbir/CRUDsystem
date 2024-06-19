CXXFLAGS = -std=c++17 -Wall

all: fb td

fb: FriendsBook.o MyADT.o Profile.o
	g++ $(CXXFLAGS) -o fb FriendsBook.o MyADT.o Profile.o

td: MyADTTestDriver.o MyADT.o Profile.o
	g++ $(CXXFLAGS) -o td MyADTTestDriver.o MyADT.o Profile.o

FriendsBook.o: FriendsBook.cpp MyADT.h Profile.h
	g++ $(CXXFLAGS) -c FriendsBook.cpp

MyADTTestDriver.o: MyADTTestDriver.cpp MyADT.h Profile.h
	g++ $(CXXFLAGS) -c MyADTTestDriver.cpp

MyADT.o: MyADT.h MyADT.cpp
	g++ $(CXXFLAGS) -c MyADT.cpp

Profile.o: Profile.h Profile.cpp
	g++ $(CXXFLAGS) -c Profile.cpp

clean:
	rm -f fb td *.o
