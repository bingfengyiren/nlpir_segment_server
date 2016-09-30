CXX = g++
DEBUG = 1
ifneq ($(DEBUG),1)
    CFLAGS = -Wall -Wunused -O3 -DOS_LINUX 
else
    CFLAGS = -Wall -DDEBUG -Wunused -g -DOS_LINUX
endif

INC_PATH = -I../depend/jsoncpp/include/
INC_PATH += -I../depend/woo/include/
INC_PATH += -I../depend/fengyongApi/include/

LINK_PATH = -L../depend/jsoncpp/lib/
LINK_PATH += -L../depend/woo/lib/
LINK_PATH += -L../depend/fengyongApi/lib/

LINK = -lpthread -lFengyoungAPI -lwoo

EXES = ./nlpir_server

.PHONY: all

all:$(EXES)

./nlpir_server:nlpir_segment_server.cpp
	echo $(LINK_PATH)
	$(CXX) $(CFLAGS) -o $@ $^ $(INC_PATH) $(LINK_PATH) $(LINK)
