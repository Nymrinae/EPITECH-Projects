import sys
import os

def usage():
    print("USAGE\n\t./301dannon file")
    print("DESCRIPTION")
    print("\tfile\tfile that contains the numbers to be sorted, separated by spaces")
    exit(84)

def checkError():
    if (len(sys.argv) != 2):
        usage()
    elif (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        usage()
    return 0

def valueError():
    print("File must contains only numbers.")
    exit(84)

def fileNotFoundError():
    print("File not found.")
    exit(84)

def fileEmptyError():
    print("File is empty. Please enter a valid file.")
    exit(84)

def readFile(file):
    try:
        if os.path.getsize(file) == 0:
            fileEmptyError()
        list = open(file, "r")
        numberList = [float(i) for i in list.read().split()]
        list.close()
        return numberList
    except ValueError:
        print("File must contains only numbers.")
        exit(84)
    except FileNotFoundError:
        print("File not found.")
        exit(84)