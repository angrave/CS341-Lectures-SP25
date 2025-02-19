CC=clang

# Hint: You can use 'find /usr -name 'openssl' to search for the openssl library
# On my Mac, I used home brew to install the x86_64 version of these libraries - hence the arch and masm options below. YMMV

OPENSSL_DIR=/usr/local/opt/openssl
CPPFLAGS=-arch x86_64 -masm=intel -I$(OPENSSL_DIR)/include -Wno-pointer-sign 
LDFLAGS=-pthread -lcrypto -L$(OPENSSL_DIR)/lib

all : miner-singlethread  miner-attempt miner-solution

miner-singlethread : miner-singlethread.c
	$(CC) $(CPPFLAGS) $(LDFLAGS) miner-singlethread.c -o miner-singlethread
	
miner-attempt: miner-attempt.c
	$(CC) $(CPPFLAGS) $(LDFLAGS) miner-attempt.c -o miner-attempt

miner-solution : miner-solution.c
	$(CC) $(CPPFLAGS) $(LDFLAGS) miner-solution.c -o miner-solution

clean:
		rm miner-singlethread miner-attempt miner-solution 2>/dev/null || true