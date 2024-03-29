CC	= g++
INCLUDE	= -I/usr/local/include
#Windows users comment-out the above line and uncomment the line below
#INCLUDE	= -I/MinGW/msys/1.0/local/include

LIBS = -L/usr/local/lib
#Windows users comment out the above line and uncomment the line below
#LIBS = -L/MinGW/msys/1.0/local/lib

CFLAGS  = -g

getURL: SimpleCurl.o SimpleCurlTest.o URLGraph.o
	$(CC) -o getURL $(INCLUDE) $(LIBS) $(CFLAGS)  SimpleCurl.o SimpleCurlTest.o URLGraph.o -lcurl

getFakeURL: SimpleFakeCurl.o SimpleFakeCurlTest.o URLGraph.o
	$(CC) -o getFakeURL $(INCLUDE) $(LIBS) $(CFLAGS)  SimpleFakeCurl.o SimpleFakeCurlTest.o URLGraph.o
.cpp.o:	
	$(CC) $(INCLUDE) $(CFLAGS) $(LIBS) -c $< -o $@

