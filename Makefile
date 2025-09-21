# Default target
all: client install

# Link object files into the executable
client: main.o mystrfunctions.o myfilefunctions.o
	gcc main.o mystrfunctions.o myfilefunctions.o -o client

# Compile each .c file into a .o file
main.o: src/main.c include/mystrfunctions.h include/myfilefunctions.h
	gcc -c -Iinclude src/main.c

mystrfunctions.o: src/mystrfunctions.c include/mystrfunctions.h
	gcc -c -Iinclude src/mystrfunctions.c

myfilefunctions.o: src/myfilefunctions.c include/myfilefunctions.h
	gcc -c -Iinclude src/myfilefunctions.c

# Clean compiled files
clean:
	rm -f *.o client

# Install the executable to /usr/bin
install: client
	@cp client ~/bin
	@chmod a+x ~/bin/client
	@echo "client successfully installed in ~/bin"


# Remove installed executable
uninstall:
	@rm -f /usr/bin/client
	@echo "client successfully un-installed"

# Phony targets (not real files)
.PHONY: all clean install uninstall
