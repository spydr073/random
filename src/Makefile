all: pcg_idris_ffi.so

pcg_idris_ffi.so : cbits/pcg_headers.h cbits/pcg_idris_ffi.o
	gcc -fPIC -g -pedantic -Wall -Wextra -ggdb3 cbits/pcg_idris_ffi.o -o pcg_idris_ffi.so -shared

clean:
	find . -name *.o   -delete
	find . -name *.ibc -delete


