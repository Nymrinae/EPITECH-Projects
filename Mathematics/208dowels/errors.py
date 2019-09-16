import sys
from print import *

def checkArgs():
    sum = 0
    args = sys.argv
    args.pop(0)

    if (len(args) is not 9):
        if not (args):
            help()
        if (args[0] == "-h"):
            help()
        else:
            printErr("Error: Arguments missing.\nCheck ./208dowels -h for more informations.")
    for i in range(0, len(args)):
        try:
            args[i] = int(args[i])
            sum += args[i]
        except ValueError:
            printErr("Error: Arguments must be integers.\nCheck ./208dowels -h for more informations.")
    if (sum != 100):
        printErr("Error: Sum of arguments must be equal to 100.")
    return args
