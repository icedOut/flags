SRC_DIR = src
BIN_DIR = bin
EXEC = tp3
TEST_EXEC = $(patsubst %.c,%,$(wildcard $(SRC_DIR)/test*.c))


.PHONY: exec bindir clean html source test testbats testbin testcunit

exec: source bindir
	cp $(SRC_DIR)/tp3 $(BIN_DIR)

bindir:
	mkdir -p $(BIN_DIR)

clean:
	make clean -C $(SRC_DIR)
	rm -rf $(BIN_DIR)
	rm -f README.html

html:
	pandoc -f markdown -o README.html README.md -c misc/github-pandoc.css

source:
	make -C $(SRC_DIR)

test: exec testcunit

testcunit:
	set -e; \
	for test in `ls $(BIN_DIR)/test*` ; do \
		$$test; \
	done
