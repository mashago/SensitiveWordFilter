default: platform libsensitive_word_filter.a 

OS:=$(shell uname -s)

CFLAG:=-Wall -g

platform:
	@echo Platform: $(OS)

clean:
	rm -rf sensitive_word_filter.o
	rm -rf libsensitive_word_filter.a
	rm -rf *.dSYM

sensitive_word_filter.o: sensitive_word_filter.cpp sensitive_word_filter.h
	g++ $(CFLAG) -c -o $@ $<

libsensitive_word_filter.a: sensitive_word_filter.o 
	ar -crus $@ $<

