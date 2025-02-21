CC = gcc
TARGET = get_10DimensionSphereVolume.out
OBJS = get_10DimensionSphereVolume.o
SRCS = get_10DimensionSphereVolume.c

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

$(OBJS) : $(SRCS)
	$(CC) -c -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
	rm $(TARGET)
