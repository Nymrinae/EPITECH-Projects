def usage():
  print("USAGE")
  print("    ./306radiator n ir jr [i j]")
  print()
  print("DESCRIPTION")
  print("    n\t\tsize of the room")
  print("    (ir, jr)\tcoordinates of the radiator")
  print("    (i, j)\tcoordinates of a point in the room")
  exit(84)

def printMatrix(matrice):
  for row in matrice:
    for item in row:
      print(item, end="\t")
    print()
  print()

def printVector(vector):
  for elem in vector:
    print(round(elem + 0.001, 1))