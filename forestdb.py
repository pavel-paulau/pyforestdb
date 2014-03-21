import pyforestdb


class ForestDB(object):

    def open(self, dbname):
        return pyforestdb.open(dbname)

    def close(self):
        return pyforestdb.close()

    def set(self, key, body):
        return pyforestdb.set(key, body)

    def get(self, key):
        return pyforestdb.get(key)
