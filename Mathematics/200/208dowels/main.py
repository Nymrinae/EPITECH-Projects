#!/usr/bin/env python3

import sys
from print import *
from maths import *
from errors import *

args = checkArgs()
x = [[]]
Ox = [0]
Tx = [0]

# Fill x/Ox/Tx
for i, c in enumerate(args):
    if (c >= 10 or (i != len(args) and Ox[-1] >= 10 and Ox[-1] >= args[i + 1])):
        x.append([])
        Ox.append(0)
        Tx.append(0)
    x[-1].append(i)
    Ox[-1] += c

Xline = []
for i in x:
    Xline.append(str(i[0]) + '-' + str(i[1]) if len(i) > 1 else str(i[0]))
Xline[-1] = Xline[-1].split('-')[0] + "+"

# calc Distribution
p = calcDistrib(args)

# calc Chi²
i = 0
X2 = 0
while i < len(x):
    if (len(x[i]) == 1):
        Tx[i] = calcTx(x[i][0], p)
    elif (len(x[i]) > 1):
        Tx[i] = calcTx(x[i][0], p) + calcTx(x[i][-1], p)
    X2 += calcX2(Ox, Tx, i)
    i = i + 1
X2 -= calcX2(Ox, Tx, -1)
Tx[-1] = 100 - (sum(Tx) - Tx[-1])
X2 += calcX2(Ox, Tx, -1)

# calc Freedom
v = calcFreedom(x)

# calc Fit
fit = calcFit(X2, v)

# print everything
printStats(Xline, Ox, Tx)
printInfos(p, X2, v, fit)