def usage():
  print('USAGE')
  print('    ./307multigrains n1 n2 n3 n4 po pw pc pb ps')
  print()
  print('DESCRIPTION')
  print('    n1      number of tons of fertilizer F1')
  print('    n2      number of tons of fertilizer F2')
  print('    n3      number of tons of fertilizer F3')
  print('    n4      number of tons of fertilizer F4')
  print('    po      price of one unit of oat')
  print('    pw      price of one unit of wheat')
  print('    pc      price of one unit of corn')
  print('    pb      price of one unit of barley')
  print('    ps      price of one unit of soy')
  exit(84)

def printResources(resources, initRightMatrice):
  print("Resources:", end="")
  for i in range(len(resources)):
    print(" {} {}".format(initRightMatrice[i], resources[i]), end="")
    if i != len(resources) - 1:
      print(",", end="")
  print('\n')

def printGrains(grains, leftMatriceVector, rightMatriceVector, initBottomMatrice):
  for i in range(len(grains)):
    found = -1
    for j in range(len(leftMatriceVector)):
      if grains[i] == leftMatriceVector[j]: found = j
    if found != -1 and rightMatriceVector[found] >= 0.005:
      printNbUnits(i, found, grains, rightMatriceVector, initBottomMatrice)
    else:
      printNoUnits(i, grains, initBottomMatrice)

def printNbUnits(i, found, grains, rightMatriceVector, initBottomMatrice):
  print("{0}: {1:.2f} units at ${2}/unit".format(grains[i], rightMatriceVector[found], -initBottomMatrice[i])) 
  
def printNoUnits(i, grains, initBottomMatrice):
  print("{}: {} units at ${}/unit".format(grains[i], 0, -initBottomMatrice[i]))

def printProdValue(prodValue):
  print()
  print("Total production value: ${0:.2f}".format(prodValue[0]))