import sys

def printErr(string):
    print(string)
    exit(84)

def help():
    print("USAGE\n    ./209poll pSize sSize p\n")
    print("DESCRIPTION")
    print("    pSize   size of the population")
    print("    sSize   size of the sample (supposed to be representative")
    print("    p       percentage of voting intentions for a specific candidate")
    exit(84)

def printFirstValues(p, s, v):
    print("Population size:         %d" %(p))
    print("Sample size:             %d" %(s))
    print("Voting intentions:       %.2f%%" %(v * 100))

def printVar(v):
    print("Variance:                %.6f" %(v))

def printInterval(p, i95, i99):
    mini95 = p * 100 - i95
    maxi95 = p * 100 + i95
    mini99 = p * 100 - i99
    maxi99 = p * 100 + i99

    if mini95 < 0:
        mini95 = 0
    if maxi95 > 100:
        maxi95 = 100
    if mini99 < 0:
        mini99 = 0
    if maxi99 > 100:
        maxi99 = 100
    print("95%% confidence interval: [%.2f%%; %.2f%%]" %(mini95, maxi95))
    print("99%% confidence interval: [%.2f%%; %.2f%%]" %(mini99, maxi99))
