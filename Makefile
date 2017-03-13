# (as instructed by binki)

.PHONY: all clean
.SUFFIXES: .o .cxx

CXXFLAGS = -Wall

OBJS = \
    src/command_line.o \
	src/kshell.o \
    src/main.o \
    src/path.o \
    src/prompt.o

HEADERS = \
    src/command_line.hxx \
    src/kshell.hxx \
    src/path.hxx \
    src/prompt.hxx

all: kshell

$(OBJS): $(HEADERS)

kshell: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o '$(@)' $(OBJS) $(LIBS)
.cxx.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o '$(@)' '$(<)'

clean:
	rm -rf src/*.o kshell
