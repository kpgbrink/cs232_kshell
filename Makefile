# (as instructed by binki)

.PHONY: all clean
.SUFFIXES: .o .cxx

OBJS = \
    src/command_line.o \
	src/kshell.o \
    src/main.o \
    src/path.o \
    src/prompt.o

all: kshell

kshell: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o '$(@)' $(OBJS) $(LIBS)
.cxx.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o '$(@)' '$(<)'

clean:
	rm -rf src/*.o kshell
