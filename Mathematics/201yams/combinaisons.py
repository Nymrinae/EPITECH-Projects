import sys
from maths import *

def buildDicesList(list):
    for i in range(1, 6):
        list.append(int(sys.argv[i]))
    return (list)

def full(dices, a, b):
    a = int(a)
    b = int(b)
    v_a = dices.count(a)
    v_b = dices.count(b)
    if (v_a == 3 and v_b == 2):
        res = 100
    else:
        if (v_a > 3):
            v_a = 3
        if (v_b > 2):
            v_b = 2
        res = calcProbaFull(v_a, v_b)
    print("chances to get a " + str(a) + " full of " + str(b) + ": %0.2f%%" % (res))

def launchGame(dices, list):
    c = list[0]
    a = list[1]
    if (len(list) > 2):
        b = int(list[2])
    if (c == "pair"):
        printResult(c, a, calcProba(dices, 2, a))
    elif (c == "three"):
        printResult("three-of-a-kind", a, calcProba(dices, 3, a))
    elif (c == "four"):
        printResult("four-of-a-kind", a, calcProba(dices, 4, a)) 
    elif (c == "full"):
        full(dices, a, b)
    elif (c == "straight"):
        exit(84)
    elif (c == "yams"):
        printResult(c, a, calcProba(dices, 5, a))
    else:
        print("Not realized yet.")
        exit(84)