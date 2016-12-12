CFLAGS := -I$(UNITY_PATH) -I$(SRC_PATH)
TESTS = $(wildcard $(TEST_PATH)*.c)

All: $(patsubst $(TEST_PATH)Test%.c, %, $(TESTS))

HELLO_WORLD_PATHS = $(OBJS_PATH)HelloWorld $(RESULTS_PATH)HelloWorld $(OUT_PATH)HelloWorld 

HelloWorldGreeting: $(HELLO_WORLD_PATHS) $(RESULTS_PATH)HelloWorld/Greeting.txt  
	@echo "\n"
	@echo "-------------------------------------------------------------------------------------"
	@echo $@
	@echo "-------------------------------------------------------------------------------------"
	@echo $(BLUE)
	@echo "`grep -s Tests $(RESULTS_PATH)HelloWorld/*.txt`"
	@echo $(OFF)
	@echo "-------------------------------------------------------------------------------------"
	@echo $(RED)
	@echo "`grep -s FAIL $(RESULTS_PATH)HelloWorld/*.txt`"
	@echo $(OFF)
	@echo "\nDONE"


$(RESULTS_PATH)HelloWorld/Greeting.txt: $(OUT_PATH)HelloWorld/Greeting.out
	@-./$< > $@ 2>&1 || :

$(OUT_PATH)HelloWorld/Greeting.out: $(OBJS_PATH)HelloWorld/TestGreeting.o $(OBJS_PATH)HelloWorld/Greeting.o $(OBJS_PATH)unity.o
	$(LINK) -o $@ $^ 

$(OBJS_PATH)HelloWorld/Test%.o: $(TEST_PATH)HelloWorld/Test%.c
	$(COMPILE) -o $@ $< $(CFLAGS)

$(OBJS_PATH)HelloWorld: $(OBJS_PATH)
	@mkdir $(OBJS_PATH)HelloWorld || :

$(RESULTS_PATH)HelloWorld: $(RESULTS_PATH)
	@mkdir $(RESULTS_PATH)HelloWorld || :

$(OUT_PATH)HelloWorld: $(OUT_PATH)
	@mkdir $(OUT_PATH)HelloWorld || :

%: $(patsubst $(TEST_PATH)%.c, $(RESULTS_PATH)%.txt, $(TEST_PATH)Test%.c)
	@echo "\n"
	@echo "-------------------------------------------------------------------------------------"
	@echo $@
	@echo "-------------------------------------------------------------------------------------"
	@echo $(BLUE)
	@echo "`grep -s Tests $(RESULTS_PATH)*.txt`"
	@echo $(OFF)
	@echo "-------------------------------------------------------------------------------------"
	@echo $(RED)
	@echo "`grep -s FAIL $(RESULTS_PATH)*.txt`"
	@echo $(OFF)
	@echo "\nDONE"

$(RESULTS_PATH)%.txt: $(OUT_PATH)%.out
	@-./$< > $@ 2>&1 || :

$(OUT_PATH)Test%.out: $(OBJS_PATH)Test%.o $(OBJS_PATH)%.o $(OBJS_PATH)unity.o
	$(LINK) -o $@ $^ 

$(OBJS_PATH)Test%.o: $(TEST_PATH)Test%.c
	$(COMPILE) -o $@ $< $(CFLAGS)

$(OBJS_PATH)unity.o: $(UNITY_PATH)unity.c
	$(COMPILE) -o $@ $< $(CFLAGS)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $< $(CFLAGS)

.PRECIOUS: $(OUT_PATH)Test%.out $(OBJS_PATH)Test%.o $(OBJS_PATH)%.o 
.PHONY: Clean All %

Clean:
	-rm $(OUT_PATH)*.out $(OBJS_PATH)*.o $(RESULTS_PATH)*.txt
