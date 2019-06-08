#-- executable
CC=gcc
MAIN=main/main.c
OUT_DIR=bin
EXE=HardestGame
SRC=components/*.c
INC=components/*.h
#-- tests
MAIN_TEST=main_test/main_test.c
CC_TEST=g++
OUT_TEST=bin_test
EXE_TEST=HardestGameTest
SRC_TEST=components_test/*.c
INC_TEST=components_test/*.h

#-- targets
all: $(MAIN)
	mkdir -p $(OUT_DIR)
	$(CC) $(MAIN) $(SRC) $(INC) -o $(OUT_DIR)/$(EXE)

test: $(MAIN_TEST)
	mkdir -p $(OUT_TEST)
	$(CC_TEST) -pthread $(MAIN_TEST) $(SRC) $(INC) $(SRC_TEST) -lgtest_main -lgtest -o $(OUT_TEST)/$(EXE_TEST) 
	(cd $(OUT_TEST); ./$(EXE_TEST))

clean:
	rm -r $(OUT_DIR) $(OUT_TEST)

