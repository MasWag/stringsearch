SRCS=$(wildcard *.cc)
PROGS=$(SRCS:%.cc=%)
CXXFLAGS=--std=c++11 -Ofast

all: $(PROGS)
%: main.hh

clean:
	$(RM) $(PROGS)
