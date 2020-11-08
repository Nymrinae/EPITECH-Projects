def checkRadiatorPointLimits(size, i, j):
  if size < 1 or (size * i + j) > size ** 2:
    exit(84)
    
def checkPointLimits(size, i, j):
  if (size * i + j) > size ** 2:
    exit(84)

def speSequence(size):
  zeroSequence = [0 for i in range(size - 2)]

  return [4] + zeroSequence[:] + [4, -16, 4] + zeroSequence[:] + [4]

def speLine(size, inc):
  firstZeroSequence = [0] * inc
  lastZeroSequence = [0] * ((size * size - inc - len(speSequence(size))))

  return firstZeroSequence + speSequence(size) + lastZeroSequence

def totalSequence(size, inc):
  if (inc < size or inc >= size * (size - 1)) or inc % size == 0 or inc % size == size - 1:
    result = size * size * [0]
    result[inc] = 1

    return result
  else :
      return speLine(size, inc - size)

def createMatrixA(size):
  matrix = [totalSequence(size, i) for i in range(size * size)]

  return matrix

def pivot(matrix, j):
  y = j

  for i in range(j, len(matrix)):
    if abs(matrix[i][j]) > abs(matrix[y][j]):
        y = i

  return y

def transvection(A, Y, i, j, m):
  A[i] = [a + b for a, b in zip(A[i], [x * m for x in A[j]])]
  Y[i] = Y[i] + m * Y[j]

def createVector(matrix, size, ir, jr):
  finalVector = [0.0 for x in range(size ** 2)]
  vector = [0.0 for x in range(size ** 2)]
  vector[ir * size + jr] = -300.0

  for i in range(0, len(matrix) - 1):
    j = pivot(matrix, i)
    matrix[i],matrix[j] = matrix[j],matrix[i]
    vector[i],vector[j] = vector[j],vector[i]
    for k in range(i + 1, len(matrix)):
      transvection(matrix, vector, k, i, (float(matrix[k][i]) * - 1.0) / float(matrix[i][i]))
  for i in range(len(matrix) - 1, -1, -1):
    for k in range(i + 1, len(matrix)):
      vector[i] = vector[i] - float(matrix[i][k]) * finalVector[k]
    finalVector[i] = vector[i] / float(matrix[i][i])

  return finalVector