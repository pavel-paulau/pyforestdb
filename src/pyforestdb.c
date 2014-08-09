#include <Python.h>
#include "forestdb.h"

fdb_handle *db;


static PyObject *
db_open(PyObject *self, PyObject *args)
{
    fdb_config config = fdb_get_default_config();

    char *dbname;
    if (!PyArg_ParseTuple(args, "s", &dbname))
        return NULL;

    fdb_status ret;
    ret = fdb_open(&db, dbname, &config);

    if (ret != FDB_RESULT_SUCCESS) {
        perror("\nError opening file");
    }

    return Py_None;
}


static PyObject *
db_close(PyObject *self, PyObject *args)
{
    fdb_status ret;

    ret = fdb_close(db);
    if (ret != FDB_RESULT_SUCCESS) {
        perror("\nError closing file");
    }

    return Py_None;
}


static PyObject *
set(PyObject *self, PyObject *args)
{
    char *key;
    char *body;
    if (!PyArg_ParseTuple(args, "ss", &key, &body))
        return NULL;

    fdb_doc *doc;
    fdb_status ret;

    fdb_doc_create(&doc, key, strlen(key), NULL, 0, body, strlen(body));
    ret = fdb_set(db, doc);

    if (ret != FDB_RESULT_SUCCESS) {
        perror("\nError during set");
    }

    return Py_None;
}


static PyObject *
get(PyObject *self, PyObject *args)
{
    char *key;
    if (!PyArg_ParseTuple(args, "s", &key))
        return NULL;

    fdb_doc *rdoc;
    fdb_status ret;

    fdb_doc_create(&rdoc, key, strlen(key), NULL, 0, NULL, 0);
    ret = fdb_get(db, rdoc);

    if (ret != FDB_RESULT_SUCCESS) {
        perror("\nError during get");
    }

    return Py_BuildValue("s", rdoc->body);
}


static PyMethodDef
ForestDbMethods[] = {
    {"open",  db_open, METH_VARARGS, "Open database file"},
    {"close",  db_close, METH_VARARGS, "Close database file"},
    {"set",  set, METH_VARARGS, "Set operation"},
    {"get",  get, METH_VARARGS, "Get operation"},
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
