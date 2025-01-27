CC = gcc
TARGET = Square_Potential_Well.out
OBJS = Square_Potential_Well.o
SRCS = Square_Potential_Well.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
