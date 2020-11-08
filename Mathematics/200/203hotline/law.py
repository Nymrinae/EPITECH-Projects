import sys
import time
from math import *

def CB(n, k):
    x = factorial(n)
    y = factorial(k)
    z = factorial (n - k)
    return (x // (y * z))

def combi(n, k):
    if (n < k):
        print("n should be < k")
        exit (84)
    print("%d-combination of a %d set:\n%d" %(k, n, CB(n, k)))

def calcbLaw(n, k, p):
    return (CB(n, k) * (p ** k) * ((1 - p)**(n - k)))

def calcpLaw(l, k):
    return (l ** k) * exp(-l)/(factorial(k))

def checkOverload(o):
    if o > 99.95:
        exit(84)

def law(d, law):
    o = 0
    n = 3500
    p = d / (3600 * 8)
    l = n * p

    print("Binomial distribution:" if law == "b" else "Poisson distribution:")
    start = time.time()
    for k in range(0, n):
        c = calcbLaw(n, k, p) if law == "b" else calcpLaw(l, k)
        if (k < 51):
            PrintTabLaw(k, c)
        if (k > 25):
            o += c
        if (k > 100):
            break
    end = time.time()
    timer = (end - start) * 1000
    o = o * 100
    if (d > 380):
        o = 100
    print("overload:  %0.1f%%" %(o))
    print("computation time: %0.2f ms" %(timer))
    return (o)

def PrintTabLaw(k, c):
    if (k != 50):
        if ((k + 1) % 6 == 0):
            print("%d -> %0.3f" %(k, c), end = '')
        else:
            print("%d -> %0.3f" %(k, c), end ='\t')
    else:
        print("%d -> %0.3f\n" %(k, c), end ='')
    if (k > 0 and ((k + 1) % 6) == 0):
           print("\n", end ='')