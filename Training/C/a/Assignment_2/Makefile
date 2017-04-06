.PHONY: clean

VPATH = source object header

SOURCE := $(shell ls ./source/) 
#SOURCE += $(shell ls ./header/)

HEADER := ./header

OBJECT := $(SOURCE:%.c=%.o) 

app : $(OBJECT)
	gcc -o $@ $^
	mv *.o ./object

%.o : %.c header.h
	gcc -c $^ -I $(HEADER)

clean:
	rm app ./object/*.o
