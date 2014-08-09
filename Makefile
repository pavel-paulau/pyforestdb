FORESTDB_SRC = ../forestdb
PYTHON_DEV = /usr/include/python2.7

build: ; \
    gcc -g -shared -O2 -fPIC \
    -o pyforestdb.so src/pyforestdb.c \
    -I ${PYTHON_DEV} \
    -I $(FORESTDB_SRC)/include/libforestdb/ \
    -lforestdb

clean: ; \
    rm -f pyforestdb.so test.fdb *.pyc

test: ; \
    python tests.py -v
