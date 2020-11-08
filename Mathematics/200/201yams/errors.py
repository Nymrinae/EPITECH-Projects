import sys
from combinaisons import launchGame

def help():
    print("USAGE\n           ./201yams d1 d2 d3 d4 d5 c\n")
    print("DESCRIPTION")
    print("\t  d1\t value of the first die (0 if not thrown)")
    print("\t  d2\t value of the second die (0 if not thrown)")
    print("\t  d3\t value of the third die (0 if not thrown)")
    print("\t  d4\t value of the fourth die (0 if not thrown)")
    print("\t  d5\t value of the fifth die (0 if not thrown)")
    print("\t  c\t expected combination")

def checkDices():
    a = 0

    if (len(sys.argv) > 1 and sys.argv[1] == "-h"):
        help()
        return (0)
    elif(len(sys.argv) != 7):
        print("The number of args should be equal to 7.")
        exit(84)
    else:
        for i in range(1, 6):
            if (int(sys.argv[i]) < 0 or int(sys.argv[i]) > 6):
                print("Dice number " + str(i) + " should be an integer between 1 and 6.")
                exit(84)
    return (1)

def checkCombi(dices):
    list = []
    list = sys.argv[6].split('_')
    combinations = ["pair", "three", "four", "full", "straight", "yams"]
    
    if (len(list) == 1 or len(list) > 3):
        print("The combination should be written as follows: <combination>_A_B")
        exit(84)
    elif (len(list) == 2):
        if(int(list[1]) < 0 or int(list[1]) > 6):
            print("The first number in expected combination should be an integer between 1 and 6.")
            exit(84)
    elif (len(list) == 3):
        if (list[0] != "full"):
            print("Only <full> can have two numbers.")
            exit(84)
        if(int(list[2]) < 0 or int(list[2]) > 6):
            print("The second number in expected combination should be an integer between 1 and 6.")
            exit(84)

    if list[0] in combinations:
        launchGame(dices, list)
    else:
        print("Combination type should be only one of those : pair, three, four, full, straight, yams")
        exit(84)



