CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		kmeanscpp.o

LIBS =

TARGET =	kmeanscpp

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
