import os
import unittest

import pyforestdb
from forestdb import ForestDB


class ImportTest(unittest.TestCase):

    def test_methods(self):
        self.assertTrue(hasattr(pyforestdb, 'open'))


class ApiTest(unittest.TestCase):

    DBNAME = 'test.fdb'
    DATA = str({'data': 12345})

    def setUp(self):
        if os.path.isfile(self.DBNAME):
            os.remove(self.DBNAME)
        open(self.DBNAME, 'w').close()

    def tearDown(self):
        if os.path.isfile(self.DBNAME):
            os.remove(self.DBNAME)

    def test_open(self):
        fdb = ForestDB()
        fdb.open(self.DBNAME)
        self.assertTrue(os.path.isfile(self.DBNAME))

    def test_close(self):
        fdb = ForestDB()
        fdb.open(self.DBNAME)
        fdb.close()

    def test_set(self):
        fdb = ForestDB()
        fdb.open(self.DBNAME)
        fdb.set("key-1", self.DATA)
        fdb.close()

    def test_get(self):
        fdb = ForestDB()
        fdb.open(self.DBNAME)
        fdb.set("key-2", self.DATA)
        self.assertEqual(fdb.get("key-2"), self.DATA)
        fdb.close()


if __name__ == '__main__':
    unittest.main()
