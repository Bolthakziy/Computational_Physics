CC = gcc
TARGET = SecondOrder_ODE.out
OBJS = SecondOrder_ODE.o
SRCS = SecondOrder_ODE.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
