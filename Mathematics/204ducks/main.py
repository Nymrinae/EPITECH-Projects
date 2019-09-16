#!/usr/bin/env python3

import sys
from maths  import *
from print  import *
from errors import *

if (checkError()):
    a = float(sys.argv[1])
    ducks(a)