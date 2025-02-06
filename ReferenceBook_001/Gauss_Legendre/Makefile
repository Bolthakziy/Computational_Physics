CC = gcc
TARGET = Gauss_Legendre.out
OBJS = Gauss_Legendre.o
SRCS = Gauss_Legendre.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
