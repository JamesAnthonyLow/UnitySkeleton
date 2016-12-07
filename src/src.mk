##Declare your object files here
##MYOBJ := $(patsubst %.o, $(OBJS_PATH)%.o, obj1.o obj2.o)

##Place your source rules here
#Program: $(RT_OBJ)
#	$(LINK) -o $(ROOT_PATH)Program.out $(MYOBJ)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $<

.PHONY: clean

clean:
	-rm $(OBJS_PATH)*.o $(ROOT_PATH)*.out
