import sys
from print import printErr, help

def checkArgs(args):
    if (len(args) != 3):
        if(len(args) == 1 and args[0] == "-h"):
            help()
        else:
            printErr("Not enough arguments. Check ./209poll -h for more informations.")
    else:
        try:
            args[0] = int(args[0])
            args[1] = int(args[1])
            args[2] = float(args[2])

            if (args[0] <= 0 or args[1] <= 0):
                printErr("Population size or sample size must be positive.")
            if (args[1] > args[0]):
                printErr("Sample size cannot be greater than Population size.")
            if (args[2] < 0 or args[2] > 100):
                printErr("Percentage of voting intentions must be between 0 and 100")
        except ValueError:
            printErr("Wrong type of arguments. int, int, float must be used.")
    return args