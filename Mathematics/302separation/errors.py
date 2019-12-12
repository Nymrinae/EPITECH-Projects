import sys

def help():
    print("USAGE\n           ./302separation file n\n           ./302separation file p1 p2")
    print("DESCRIPTION")
    print("\tfile\tfile that contains the list of Facebook connections in the form of XX is friends with XY")
    print("\tn\tmaximum size of paths")
    print("\tp1/p2\tnames of people in the file")
    exit(84)

def checkError():
    if (len(sys.argv) < 2 or len(sys.argv) > 4):
        help()
    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        help()
    if (len(sys.argv) == 3):
        try:
            int(sys.argv[2])
        except ValueError:
            help()
    return sys.argv[2:]

def parseFile(file):
    try:
        f = open(file, "r")
        content = [line.rstrip().replace(' is friends with ', '-') for line in f]
        
        return content
    except FileNotFoundError:
        print("File not found.")
        exit(84)