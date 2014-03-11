#include <Python.h>
#include "forestdb.h"


static PyObject *
opendb(PyObject *self, PyObject *args)
{
    fdb_handle db;
    fdb_config config;

    memset(&config, 0, sizeof(fdb_config));
    config.chunksize = config.offsetsize = sizeof(uint64_t);

    char *dbname;
    if (!PyArg_ParseTuple(args, "s", &dbname))
        return NULL;
    fdb_open(&db, dbname, &config);

    return Py_None;
}


static PyMethodDef
ForestDbMethods[] = {
    {"open",  opendb, METH_VARARGS, "Open database file"},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initpyforestdb(void)
{
    PyObject *m;

    m = Py_InitModule("pyforestdb", ForestDbMethods);
    if (m == NULL)
        return;
}
