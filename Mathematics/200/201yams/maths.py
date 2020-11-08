from math import *

def printResult(combinaison, value, res):
    print("chances to get a " + value + " " + combinaison + ":  %0.2f%%" % (res))

def binomiale(a, b):
    res = (factorial(a) / (factorial(b) * factorial(a-b))) * pow(1/6, b) * pow(5/6, a-b)
    return (res)

def calcProba(list, c, nb):
    res = 0
    times = list.count(int(nb))
    if (times >= c):
        res = 1
    else:
        for i in range(c - times, 5 - times + 1):
            res += binomiale(5 - times, i)
    return (res * 100)

def calcProbaFull(x, y):
    c = factorial(5 - x - y) / (factorial(3 - y) * factorial((5 - y - x) - (3 - x)))
    return (c) / 6**(5 - x - y) * 100