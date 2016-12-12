CFLAGS := -I$(UNITY_PATH) -I$(SRC_PATH)
TESTS = $(wildcard $(TEST_PATH)*.c)

All: $(patsubst $(TEST_PATH)Test%.c, %, $(TESTS))

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
