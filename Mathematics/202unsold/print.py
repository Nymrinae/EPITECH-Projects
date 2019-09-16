import sys
from math import *

def print_03f(x):
    print("\t%0.3f" %(x), end='')

def print_Y(y):
    if (y == 60):
        print("X law", end = '')
    else:
        print("Y=%d" %(y), end = '')

def print_XY():
    print("------------------------------------------------------")
    print("\tX=10\tX=20\tX=30\tX=40\tX=50\tY law")

def print_Z():
    print("------------------------------------------------------")
    print("z\t 20\t 30\t 40\t 50 \t60 \t70 \t80 \t90 \t100 \ttotal\np(Z=z)", end = '')

def print_footer(vX, vY, tX, tY):
    print("------------------------------------------------------")
    print("expected value of X:\t%0.1f" %(tX))
    print("variance of X:\t\t%0.1f" %(vX))
    print("expected value of Y:\t%0.1f" %(tY))
    print("variance of Y:\t\t%0.1f" %(vY))
    print("expected value of Z:\t%0.1f" %(tX + tY))
    print("variance of Z:\t\t%0.1f" %(vX + vY))
    print("------------------------------------------------------")