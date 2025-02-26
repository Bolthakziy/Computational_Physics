CC = gcc
TARGET = FirstOrder_OrdinaryDifferentialEquation.out
OBJS = FirstOrder_OrdinaryDifferentialEquation.o
SRCS = FirstOrder_OrdinaryDifferentialEquation.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
