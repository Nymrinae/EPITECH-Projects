import sys

def help():
    print("USAGE\n           ./204ducks a\n")
    print("DESCRIPTION")
    print("\t  a\tconstant")

def checkError():
    if (len(sys.argv) > 2):
        print("The number of args should be 2.\n./204ducks -h for more information.")
        exit(84)
    elif (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        help()
        exit(84)
    else:
        try:
            a = float(sys.argv[1])
            if (a <= 0.0 or a > 2.5):
                exit(84)
        except:
            print("Wrong argument value.")
            exit(84)
    return 1
