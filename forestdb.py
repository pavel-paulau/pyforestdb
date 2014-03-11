import pyforestdb


def opendb(dbname):
    return ForestDB(dbname)


class ForestDB(object):

    def __init__(self, dbname):
        pyforestdb.open(dbname)
