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
	$(CC) -g -o0 $(MAIN) $(SRC) $(INC) -o $(OUT_DIR)/$(EXE)

build_lib:
	$(CC) -c $(SRC)

test: build_lib $(MAIN_TEST) $(SRC) $(INC)
	-mkdir -p $(OUT_TEST)
	$(CC_TEST) -g -o0 -pthread $(MAIN_TEST) *.o -lgtest_main -lgtest -o $(OUT_TEST)/$(EXE_TEST) 
	(cd $(OUT_TEST); ./$(EXE_TEST))

clean:
	-rm -r $(OUT_DIR) $(OUT_TEST)
	-rm *.o

