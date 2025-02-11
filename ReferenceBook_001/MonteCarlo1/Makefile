CC = gcc
TARGET = MonteCarloIntegral1.out
OBJS = MonteCarloIntegral1.o
SRCS = MonteCarloIntegral1.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
