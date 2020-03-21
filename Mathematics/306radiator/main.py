import sys
import logging
from print import *
from functions import *

def init():
  try:
    size = int(sys.argv[1])
    ir = int(sys.argv[2])
    jr = int(sys.argv[3])
    checkRadiatorPointLimits(size, ir, jr)
    if (len(sys.argv) == 4):
      run(False, size, ir, jr, 0, 0)
    else:
      i = int(sys.argv[4])
      j = int(sys.argv[5])
      checkPointLimits(size, i, j)
      run(True, size, ir, jr, i, j)
  except:
    logging.exception('')

def run(isCoordinates, size, ir, jr, i, j):
  matrix = createMatrixA(size)
  if not isCoordinates:
    printMatrix(matrix)
  vector = createVector(matrix, size, ir, jr)
  print(round(vector[size * i + j] + 0.001, 1)) if isCoordinates else printVector(vector)

init()