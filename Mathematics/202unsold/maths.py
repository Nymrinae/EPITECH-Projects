import sys
from print import *

X = list()
Y = list()
total_list = list()

def probability(a, b, x, y):
    return (((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150)))

def XYLaw(a, b):
    i = 0
    vX = 0.0
    vY = 0.0

    print_XY()
    for y in range(10, 70, 10):
        print_Y(y)
        for x in range (10, 60, 10):
            vX = probability(a, b, x, y)
            vY += vX
            if (y == 60):
                j = i
                total = 0.0
                for c in range(0, 5):
                    total += total_list[j]
                    j += 5
                print_03f(total)
                i += 1
                X.append(total)
            else:
                total_list.append(vX)
                print_03f(vX)
        if (y == 60):
            print("\t1")
        else:
            print("\t%0.3f" %(vY))
            Y.append(vY)
            vY = 0.0

def ZLaw(a, b):
    total = 0.0

    print_Z()
    for z in range(20, 110, 10):
        vX = 0.0
        vY = 0.0
        for y in range(10, 70, 10):
            for x in range(10, 60, 10):
                vX = probability(a, b, x, y)
                if (x + y == z and y < 60):
                    vY += vX
        print_03f(vY)
        total += vY
    print("\t1")

def expected(a, b):
    i = 0
    vX = 0.0
    vY = 0.0
    totalX = 0.0
    totalY = 0.0

    for x in range(10, 60, 10):
        totalX += X[i] * x
        totalY += Y[i] * x
        i += 1
    for i in range(0, 5):
        vX += ((i + 1) * 10 - totalX) * ((i + 1) * 10 - totalX) * X[i]
        vY += ((i + 1) * 10 - totalY) * ((i + 1) * 10 - totalY) * Y[i]
    print_footer(vX, vY, totalX, totalY)