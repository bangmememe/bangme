CC = /usr/bin/gcc
CFLAGS = -fdiagnostics-color=always -g -I/usr/include/mysql
LDFLAGS = -lmysqlclient

SRC_DIR = /home/bangme/bangme/balling
BIN_DIR = $(SRC_DIR)

SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/balling.c
BIN_FILE = $(BIN_DIR)/balling

all: $(BIN_FILE)

$(BIN_FILE): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(BIN_FILE) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(BIN_FILE)
