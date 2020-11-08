import sys
from functions import *

def help():
    print("USAGE\n    ./205IQ u s [IQ1] [IQ2]\n")
    print("DESCRIPTION")
    print("    u       mean")
    print("    s       standard deviation")
    print("    IQ1     minimum IQ")
    print("    IQ2     maximum IQ")
    exit(84)

def err(s):
    print(s)
    exit(84)

def print_tab(tab):
    i = 0
    while (i <= 200):
        print("%d %0.5f" %(i, tab[i]))
        i += 1

def print_inf_IQ(res, iq):
    print("%0.1f%% of people have an IQ inferior to %d" %(res, iq))

def print_between_IQ(res, iq1, iq2):
    print("%0.1f%% of people have an IQ between %d and %d" %(res, iq1, iq2))
