CC = gcc
TARGET = Bisection_Method.out
OBJS = Bisection_Method.o
SRCS = Bisection_Method.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
