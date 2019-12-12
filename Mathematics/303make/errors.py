import sys

def help():
  print("USAGE\n    ./303make makefile [file]")
  print("DESCRIPTION")
  print("    makefile\tname of the makefile")
  print("    file\tname of a recently modified file")
  exit(84)

def checkError():
    if (len(sys.argv) < 2 or len(sys.argv) > 3):
        help()
    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        help()
    return sys.argv[1:]

def parseFile(file):
    separator = ':'
    content = {}
    files = []
    lines = []
    try:
        file = open(file, 'r')
        for line in file.readlines():
            line = line.rstrip()
            if ":" in line:
         
                line = line.split(':')
                key = line[0]
                deps = line[1].strip().split()
                if not key in files: files.append(key)
                for dep in deps:
                    if not dep in files: files.append(dep)
                content[key] = deps
            elif line:
                lines.append(line.split())
        return content, sorted(files)
    except FileNotFoundError:
        print("File not found.")
        exit(84)