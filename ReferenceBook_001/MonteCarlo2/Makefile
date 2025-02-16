CC = gcc
TARGET = MonteCarlo2.out
OBJS = MonteCarlo2.o
SRCS = MonteCarlo2.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
