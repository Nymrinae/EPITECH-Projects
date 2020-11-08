#!/usr/bin/env python3

import sys
from math import *
from print import *
from errors import *

args = checkArgs()
n =   args[0]
a =   args[1]
hm =  args[2]
sd =  args[3]

while (1):
    ui = userInput()
    m = a * n
    sqm = (sd ** 2 + a ** 2) * n
    n += 1
    a = (m + ui) / n
    sd = sqrt(((sqm + ui ** 2) / n) - (a ** 2))
    rms = sqrt(a ** 2 + sd ** 2)
    hm = n / ((1 / ui) + ((n - 1) / hm))
    printStats(n, sd, a, rms, hm)