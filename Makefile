
SRC=$(wildcard *.c)
EXE=elfinfo

all: $(EXE)

$(EXE): $(SRC)
	@clang -o $(EXE) $(SRC)



