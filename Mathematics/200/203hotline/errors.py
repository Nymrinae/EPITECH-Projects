import sys

def help():
    print("USAGE\n           ./203hotline [n k | d]\n")
    print("DESCRIPTION")
    print("\t  n\tn value for the computation of (n k)")
    print("\t  k\tk value for the computation of (n k)")
    print("\t  d\taverage duration of calls (in seconds)")

def checkError():
    if (len(sys.argv) > 3 or len(sys.argv) < 2):
        print("The number of args should be either 2 or 3.\n./203hotline -h for more information.")
        exit(84)
    elif (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        help()
        exit(84)
    else:
        try:
            n = int(sys.argv[1])
            if (n > 9275):
                exit(84)
            if (len(sys.argv) == 3):
                k = int(sys.argv[2])
        except:
            print("n and k should be integers")
            exit(84)
    return 1
