CC = gcc
TARGET = Newton_Raphson_Method.out
OBJS = Newton_Raphson_Method.o
SRCS = Newton_Raphson_Method.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
