#!/usr/bin/env python3

import sys
from math import *
from print import *
from errors import *

args = sys.argv
args.pop(0)

if (checkArgs(args)):
    pSize = args[0]
    sSize = args[1]
    p = args[2] / 100

    printFirstValues(pSize, sSize, p)
    var = ((p * (1 - p)) / sSize) * ((pSize - sSize) / (pSize - 1))
    printVar(var)
    i95 = (2 * 1.96 * sqrt(var)) / 2 * 100
    i99 = (2 * 2.58 * sqrt(var)) / 2 * 100
    printInterval(p, i95, i99)