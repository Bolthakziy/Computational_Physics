CC = gcc
TARGET = PhysicalPendulum.out
OBJS = PhysicalPendulum.o
SRCS = PhysicalPendulum.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
