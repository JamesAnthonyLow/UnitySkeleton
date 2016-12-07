BUS_OBJ := $(patsubst %.o, $(OBJS_PATH)%.o, util.o BusController.o)
RT_OBJ := $(patsubst %.o, $(OBJS_PATH)%.o, util.o RT.o)

all: BusController RemoteTerminal

BusController: $(BUS_OBJ)
	$(LINK) -o $(ROOT_PATH)BC.out $(BUS_OBJ)

RemoteTerminal: $(RT_OBJ)
	$(LINK) -o $(ROOT_PATH)RT.out $(RT_OBJ)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $<

.PHONY: all clean

clean:
	-rm $(OBJS_PATH)*.o $(ROOT_PATH)*.out
