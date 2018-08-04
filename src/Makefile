CC = gcc
CFLAGS = -g -std=c11 -W -Wall `pkg-config --cflags --libs jansson` `pkg-config --cflags cunit`
LFLAGS = -ljansson
EXEC = tp3
TEST_IMPL = $(wildcard test*.c)
AUXI_IMPL = $(filter-out $(TEST_IMPL) $(EXEC).c,$(wildcard *.c))
AUXI_OBJS = $(patsubst %.c,%.o,$(AUXI_IMPL))
TEST_OBJS = $(patsubst %.c,%.o,$(TEST_IMPL))
TEST_EXEC = $(patsubst %.c,%,$(TEST_IMPL))

$(EXEC): $(AUXI_OBJS) $(EXEC).o
	$(CC) $(EXEC).o $(AUXI_OBJS) $(LFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean exec test


clean:
	rm -f *.o
	rm -rf $(EXEC)



exec: $(EXEC)
	./$(EXEC)




