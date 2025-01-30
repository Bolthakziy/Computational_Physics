CC = gcc
TARGET = TrapezoidalRule.out
OBJS = TrapezoidalRule.o
SRCS = TrapezoidalRule.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
