CC = gcc
TARGET = MultipleIntegral.out
OBJS = MultipleIntegral.o
SRCS = MultipleIntegral.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
