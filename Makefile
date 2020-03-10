CC=g++  -std=c++11
CFLAGS=-c -Wpedantic -Ofast
LDFLAGS=
SOURCES=diseaseMonitor.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=diseaseMonitor
TESTSOURCE=ourunit.cpp
TESTEXEC=ourunit


#syspro
#kuriws
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

test:
	$(CC) -o $(TESTEXEC) $(TESTSOURCE)

run:
	./$(EXECUTABLE) -p /home/demetres/Documents/sxoli/SYSPRO/FINAL_20/inputs/ass1_records.txt -h1 40 -h2 41 -b 20

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TESTEXEC)

#./diseaseMonitor -p /home/demetres/Documents/sxoli/SYSPRO/FINAL_20/inputs/ass1_records.txt -h1 40 -h2 41 -b 20
