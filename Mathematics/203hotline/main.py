#!/usr/bin/env python3

import sys
from law import *
from errors import *

if(checkError()):
    if (len(sys.argv) == 2):
        d = int(sys.argv[1])
        o = law(d, "b")
        print("")
        law(d, "p")
        checkOverload(o)
    elif(len(sys.argv) == 3):
        n = int(sys.argv[1])
        k = int(sys.argv[2])
        combi(n, k)