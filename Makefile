FORESTDB_SRC = /home/pavel/dev/src/forestdb
PYTHON_DEV = /usr/include/python2.7

build: ; \
    gcc -g -shared -O2 -fPIC \
    -o pyforestdb.so pyforestdb.c \
    -I $(PYTHON_DEV) \
    -I $(FORESTDB_SRC)/include \
    -I $(FORESTDB_SRC)/option \
    -I $(FORESTDB_SRC)/util \
    -I $(FORESTDB_SRC)/src \
    -L $(FORESTDB_SRC) \
    -lforestdb

clean: ; \
    rm -f pyforestdb.so \
    rm -f test.fdb

test: ; \
    python tests.py -v
