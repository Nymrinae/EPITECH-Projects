import sys
from math import *

def f(a, t):
    return (a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t))

def F(a, t):
    return (-a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t))

def espf(a):
    return ((3/4) + (3 * a) / 8)

def ecf(a):
    dev = 0.0
    prec = 0.001
    n = 100/prec
    rt = espf(a)
    t = 0.0

    for i in range(0, int(n)):
        t = i * prec
        dev += pow(t - rt, 2) * f(a, t)
    
    dev = sqrt(dev * prec)
    return dev

def ducks_timing(a, m):
    return ((F(a, m) - F(a, 0)) * 100)

def get_time(p, a):
    i = 1.0
    while (True):
        if (F(a, i / 60) - F(a, 0) >= p):
            return i
        i += 0.01
