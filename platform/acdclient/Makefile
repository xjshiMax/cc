BINNAME = acd_client

WORKROOT=../../

INC_PATH  = -I.
INC_PATH += -I$(WORKROOT)/interface/output/bgcc/include/
INC_PATH += -I$(WORKROOT)/interface/output/acd/include

LIB_PATH  = -L$(WORKROOT)/interface/output/bgcc/lib/
LIB_PATH += -L$(WORKROOT)/interface/output/acd/lib/linux/


CFLAGS = -Wall -W -pipe -g 
LDFLAGS = -lacd -lbgcc -lssl  -lcrypto -lpthread

SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o, $(SOURCES))
CC=g++

all: $(BINNAME)

$(BINNAME):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(INC_PATH) $(LIB_PATH) $(LDFLAGS)
	
$(OBJS):%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ $(INC_PATH) -c $<
clean:
	rm -f $(OBJS)
	rm -f $(BINNAME)