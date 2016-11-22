default: platform test 

OS:=$(shell uname -s)

CFLAG:=-Wall -g

platform:
	@echo Platform: $(OS)

clean:
	rm -rf test
	rm -rf *.dSYM

test: test.cpp
	g++ $(CFLAG) -o $@ $^ -I../ ../libsensitive_word_filter.a

