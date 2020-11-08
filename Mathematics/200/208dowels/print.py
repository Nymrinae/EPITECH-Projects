import sys
from maths import *

def printErr(string):
    print(string)
    exit(84)

def help():
    print("USAGE\n   ./208dowels 00 01 02 03 04 05 06 07 08\n")
    print("DESCRIPTION\n    0i    size of the observed class")
    exit(84)

def printx(x):
    print(" x    ", end="")
    for i in x:
        print("| %s\t" %(i), end="")
    print("| Total")

def printOx(x):
    print(" Ox   ", end="")
    for i in x:
        print("| %s\t" %(i), end="")
    print("| 100")

def printTx(x):
    print(" Tx   ", end="")
    for i in x:
        print("| %.1f\t" %(i), end="")
    print("| 100")
    return

def printStats(x, Ox, Tx):
    printx(x)
    printOx(Ox)
    printTx(Tx)

def printInfos(p, c, v, fit):
    print("Distribution:\t\tB(100, %0.4f)" %(p))
    print("Chi-squared:\t\t%0.3f" %(c))
    print("Degrees of freedom:\t%d" %(v))
    print("Fit validity:\t\t%s" %(fit))