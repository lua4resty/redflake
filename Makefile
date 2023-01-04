.PHONY: all install uninstall clean

INSTALL = install
INSTALL_BIN = /usr/local/bin

CFLAGS = -std=c99 -Wall -O2

REDFLAKE = redflake

all: $(REDFLAKE)

$(REDFLAKE): redflake.c
	$(CC) $(CFLAGS) -o $@ $^

install: $(REDFLAKE)
	$(INSTALL) $< $(INSTALL_BIN)

uninstall:
	$(RM) $(INSTALL_BIN)/$(REDFLAKE)

clean:
	$(RM) *.o $(REDFLAKE)
