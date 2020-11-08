#!usr/bin/env python3

import sys
from maths import XYLaw, ZLaw, expected
from errors import checkPiece

if(checkPiece()):
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    XYLaw(a, b)
    ZLaw(a, b)
    expected(a, b)