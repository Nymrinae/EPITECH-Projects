#!/usr/bin/env python3
import sys
import argparse
from print import *

OAT_QUANTITY    = {'F1':1, 'F2':2, 'F3':2, 'F4':0}
WHEAT_QUANTITY  = {'F1':0, 'F2':2, 'F3':1, 'F4':0}
CORN_QUANTITY   = {'F1':1, 'F2':0, 'F3':0, 'F4':3}
BARLEY_QUANTITY = {'F1':0, 'F2':1, 'F3':1, 'F4':1}
SOY_QUANTITY    = {'F1':2, 'F2':0, 'F3':0, 'F4':2}
ALL_GRAINS = ['Oat', 'Wheat', 'Corn', 'Barley', 'Soy']
ALL_FERTILIZERS = ['F1', 'F2', 'F3', 'F4']
ALL_DISTANCES = ['S1', 'S2', 'S3', 'S4']
ALL_QUANTITIES = [OAT_QUANTITY, WHEAT_QUANTITY, CORN_QUANTITY, BARLEY_QUANTITY, SOY_QUANTITY]

def initArg():
  ap = argparse.ArgumentParser()
  ap.add_argument("n1", help="number of tons of fertilizer F1")
  ap.add_argument("n2", help="number of tons of fertilizer F2")
  ap.add_argument("n3", help="number of tons of fertilizer F3")
  ap.add_argument("n4", help="number of tons of fertilizer F4")
  ap.add_argument("po", help="price of one unit of oat")
  ap.add_argument("pw", help="price of one unit of wheat")
  ap.add_argument("pc", help="price of one unit of corn")
  ap.add_argument("pb", help="price of one unit of barley")
  ap.add_argument("ps", help="price of one unit of soy")

  try:
    result = vars(ap.parse_args())
  except SystemExit:
    exit(84)
  else:
    return result

def findPivot(matrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector):
  minValue = 0
  x = -1
  y = -1
  
  for i in range(len(ALL_GRAINS)):
    if bottomMatriceVector[i] < minValue:
      minValue = bottomMatriceVector[i]
      x = i
  if minValue >= 0:
    return None
  for i in range(len(rightMatriceVector)):
    if matrice[i][x] > 0 and rightMatriceVector[i] / matrice[i][x] > 0:
      minValue = rightMatriceVector[i] / matrice[i][x]
      y = i
      break
  for i in range(len(matrice)):
    if matrice[i][x] > 0 and rightMatriceVector[i] / matrice[i][x] < minValue:
      minValue = rightMatriceVector[i] / matrice[i][x]
      y = i
  if x == -1 or y == -1:
    return None
  return (y, x)

def step(matrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector, total):
  pivotCoord = findPivot(matrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector)
 
  if pivotCoord is not None:
    (y, x) = pivotCoord
    pivot = matrice[y][x]
    leftMatriceVector[y] = ALL_GRAINS[x]
    for j in range(len(matrice[y])):
      matrice[y][j] /= pivot
    rightMatriceVector[y] /= pivot
    for i in range(len(matrice)):
      if i != y:
        multiplicator = matrice[i][x]
        for j in range(len(matrice[i])):
          matrice[i][j] -= multiplicator * matrice[y][j]
        rightMatriceVector[i] -= multiplicator * rightMatriceVector[y]
    multiplicator = bottomMatriceVector[x]
    for j in range(len(bottomMatriceVector)):
      bottomMatriceVector[j] -= multiplicator * matrice[y][j]
    total[0] -= multiplicator * rightMatriceVector[y]# -= ?
    return 0
  return 1

def process(matrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector, total):
  i = 0
  while not step(matrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector, total):
    pass

def display(initRightMatrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector, total, initBottomMatrice):
  printResources(ALL_FERTILIZERS, initRightMatrice)
  printGrains(ALL_GRAINS, leftMatriceVector, rightMatriceVector, initBottomMatrice)
  printProdValue(total)

def main():
  if '-h' in sys.argv:
    usage()
  args = initArg()
  matrice = []
  rightMatriceVector = []
  bottomMatriceVector = []
  leftMatriceVector = ALL_DISTANCES[:]
  total = [0]
  try:
    for i in range(len(ALL_FERTILIZERS)):
      line = []
      for qtt in ALL_QUANTITIES:
        line.append(qtt[ALL_FERTILIZERS[i]])
      for j in range(len(ALL_FERTILIZERS)):
          line.append(1) if i == j else line.append(0)
      line.append(0)
      matrice.append(line)
    if int(args['n1']) >= 0:
      rightMatriceVector.append(int(args['n1']))
    if int(args['n2']) >= 0:
      rightMatriceVector.append(int(args['n2']))
    if int(args['n3']) >= 0:
      rightMatriceVector.append(int(args['n3']))
    if int(args['n4']) >= 0:
      rightMatriceVector.append(int(args['n4']))
    if int(args['po']) >= 0:
      bottomMatriceVector.append(-int(args['po']))
    if int(args['pw']) >= 0:
      bottomMatriceVector.append(-int(args['pw']))
    if int(args['pc']) >= 0:
      bottomMatriceVector.append(-int(args['pc']))
    if int(args['pb']) >= 0:
      bottomMatriceVector.append(-int(args['pb']))
    if int(args['ps']) >= 0:
      bottomMatriceVector.append(-int(args['ps']))
    for i in range(len(ALL_FERTILIZERS)):
      bottomMatriceVector.append(0)
    bottomMatriceVector.append(1)
  except ValueError:
    print("Bad type of arguments.")
    exit(84)
  else:
    initRightMatrice = rightMatriceVector[:]
    initBottomMatrice = bottomMatriceVector[:]
    process(matrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector, total)
    display(initRightMatrice, bottomMatriceVector, rightMatriceVector, leftMatriceVector, total, initBottomMatrice)

    return 0

if __name__ == "__main__":
  main()
