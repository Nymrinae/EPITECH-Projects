import sys
from print import help, printerr

def checkArgs():
    args = sys.argv
    args.pop(0)
    args = argstoint(args)
    checkargsvalue(args)
    return (args)

def argstoint(args):
    if not (args):
        help()
    for i in range(0, len(args)):
        try:
            if(len(args) == 4 and args[i] != "-h"):
                args[i] = int(args[i]) if i == 0 else float(args[i])
            else:
                help()
        except ValueError:
            printerr("Args's type must be either int or float.")
    return args

def checkargsvalue(args):
    for i in range(0, len(args)):
        if(args[i] <= 0):
            printerr("Args must be positive.")