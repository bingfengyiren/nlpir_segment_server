CXX = g++
DEBUG = 1
ifneq ($(DEBUG),1)
    CFLAGS = -Wall -Wunused -O3 -DOS_LINUX 
else
    CFLAGS = -Wall -DDEBUG -Wunused -g -DOS_LINUX
endif

SRC_PATH = ./src/
SERV_PATH = ./server/

INC_PATH = -I./depend/jsoncpp/include/
INC_PATH += -I./depend/NLP/include/
INC_PATH += -I./depend/chardet/include/
INC_PATH += -I./depend/fengyongApi/include/

LINK_PATH = -L./depend/jsoncpp/lib/
LINK_PATH += -L./depend/NLP/lib/
LINK_PATH += -L./depend/chardet/lib/
LINK_PATH += -L./depend/fengyongApi/lib/

LINK = -lNLPIR -ljsoncpp -lpthread -luchardet -lFengyoungAPI

OBJS = $(SRC_PATH)/segment.o

EXES = ./bin/nlpir

.PHONY: all

all:$(EXES)

./bin/nlpir: $(OBJS)
	echo $(LINK_PATH)
	$(CXX) $(CFLAGS) -o $@ $^ $(INC_PATH) $(LINK_PATH) $(LINK)

.SUFFIXES: .o .cpp .h

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(OBJS)
