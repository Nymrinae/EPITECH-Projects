import sys
from math import *

def init_list():
    list = sys.argv
    list.pop(0)

    for i in range(0, len(list)):
        try:
            if(list[i] != "-h"):
                list[i] = int(list[i])
        except:
            print("Incorrect args")
            exit(84)
    return list

def f(x, l, o):
    return (1 / (o * sqrt(2 * pi))) * exp(-0.5 * pow((x - l) / o, 2))

def density(l, o):
    i = 0
    res = 0
    tab = list()

    while (i <= 200):
        res = f(i, l, o)
        tab.append(res)
        i += 1
    return tab

def integrale(f, l, o, min, max):
    s = 0
    while (min < max):
        s += f(min, l, o)
        min += 0.01
    return s