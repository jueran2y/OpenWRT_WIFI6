XX = g++
CFLAGS += -O2 -Wno-implicit-function-declaration -Wno-int-conversion

TARGET = ./hser2net_writekey

%.o: %.c *.h 
	$(CC) $(CFLAGS) -c $< -o $@

SOURCES = $(wildcard *.c *.cpp)
OBJS = key.o des.o flash_mtd.o sha.o

hser2net:$(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
