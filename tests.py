import os
import unittest

import pyforestdb
import forestdb


class ImportTest(unittest.TestCase):

    def test_methods(self):
        """Checking that APIs are exposed and imported correctly"""
        self.assertTrue(hasattr(pyforestdb, 'open'))


class ApiTest(unittest.TestCase):

    DBNAME = 'test.fdb'

    def setUp(self):
        if os.path.isfile(self.DBNAME):
            os.remove(self.DBNAME)

    def tearDown(self):
        if os.path.isfile(self.DBNAME):
            os.remove(self.DBNAME)

    def test_open(self):
        """Checking handler API: `open`"""
        forestdb.opendb(self.DBNAME)
        self.assertTrue(os.path.isfile(self.DBNAME))


if __name__ == '__main__':
    unittest.main()
