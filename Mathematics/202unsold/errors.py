import sys

def help():
    print("USAGE\n           ./202unsold a b\n")
    print("DESCRIPTION")
    print("\t  a\tconstant computed from the past results")
    print("\t  b\tconstant computed from the past results")

def checkPiece():
    if(len(sys.argv)!= 3):
        if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
            help()
        else:
            print("The number of args should be equal to 3.")
            exit(84)
    else:
        try:
            a = int(sys.argv[1])
            b = int(sys.argv[2])
            if (a <= 50 or b <= 50):
                print("a and b should be greater than 50.")
                exit(84)
        except ValueError:
            print("a and b must be integers greater than 50.")
            exit(84)
    return (1)