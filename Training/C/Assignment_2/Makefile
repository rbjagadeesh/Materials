.PHONY: clean

VPATH = source1 source2 object header

SOURCE := $(shell ls ./source1/) 
SOURCE += $(shell ls ./source2/) 
#SOURCE += $(shell ls ./header/)

HEADER := ./header

OBJECT := $(SOURCE:%.c=%.o) 

app : $(OBJECT)
	gcc -o $@ $^
	mv *.o ./object
	@echo "my executable is" $@

%.o : %.c header.h
	gcc -c $^ -I $(HEADER)

clean:
	-rm app
	rm ./object/*.o
