import sys

def printerr(err):
    print(err)
    exit(84)

def help():
    print("USAGE\n\t./206neutrinos n a h sd\n")
    print("DESCRIPTION")
    print("   n\t   number of values")
    print("   a\t   arithmetic mean")
    print("   h\t   harmonic mean")
    print("   sd\t   standard deviation")
    exit(84)

def userInput():
    i = input("Enter next value: ")
    if (i == "END"):
        exit(0)
    try:
        i = float(i)
    except ValueError:
        printerr("Value must be a number.")
    return i

def printStats(n, sd, a, rms, h):
    print("    Number of values:    %d" %(n))
    print("    Standard deviation:  %.2f" %(sd))
    print("    Arithmetic mean:     %.2f" %(a))
    print("    Root mean square:    %.2f" %(rms))
    print("    Harmonic mean:       %.2f" %(h))
    print("")

