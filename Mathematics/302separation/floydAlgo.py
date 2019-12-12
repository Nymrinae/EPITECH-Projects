from print import *
from errors import help

def createAdjacencyMatrix(persons):
    size = len(persons)
    matrix = [[0 for x in range(size)] for y in range(size)]
    
    for x in range(size):
        for y in range(size):
            if persons[x].name in persons[y].connections:
                matrix[x][y] = 1

    return matrix

def removeZeroinMatrix(matrix):
    size = len(matrix)

    for x in range(size):
        for y in range(size):
            if matrix[x][y] == 0 and x != y:
                matrix[x][y] = -1
    return matrix

def cleanMatrix(matrix, n):
    size = len(matrix)
    
    for x in range(size):
        for y in range(size):
            if matrix[x][y] > int(n):
                matrix[x][y] = 0

    return matrix

def createFinalMatrix(args, persons):
    if len(args) == 1: 
        printPersonsList(persons)
    adjMatrix = createAdjacencyMatrix(persons)
    if len(args) == 1: 
        printMatrix(adjMatrix)
    adjMatrix = removeZeroinMatrix(adjMatrix)
    finalMatrix = floydAlgorithm(adjMatrix)
    
    return finalMatrix

def checkUsersInMatrix(matrix, persons, p1, p2):
    size = len(matrix)
    indexp1 = -1
    indexp2 = -1
    
    for person in persons:
        if p1 == person.name: indexp1 = person.index
        if p2 == person.name: indexp2 = person.index
    
    printSeparationDegree(p1, p2, matrix[indexp1][indexp2] if indexp1 != -1 and indexp2 != -1 else -1)

def floydAlgorithm(matrix):
    size = len(matrix)

    for k in range(size):
        for i in range(size):
            for j in range(size):
                if matrix[i][k] != -1 and matrix[k][j] != -1:
                    if matrix[i][j] == -1 or matrix[i][j] > matrix[i][k] + matrix[k][j]:
                        matrix[i][j] = matrix[i][k] + matrix[k][j]

    return matrix

def withMaxConnections(max, matrix):
    finalMatrix = cleanMatrix(matrix, max)
    printMatrix(finalMatrix)

def withFriends(args, persons, matrix):
    try:
        p1 = args[0]
        p2 = args[1]
    except IndexError:
        help()
    checkUsersInMatrix(matrix, persons, p1, p2)