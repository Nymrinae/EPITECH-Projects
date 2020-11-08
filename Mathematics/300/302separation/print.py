def printSeparationDegree(p1, p2, n):
    print("Degree of separation between %s and %s: %d" %(p1, p2, n))

def printPersonsList(persons):
    for person in persons:
        print(person.name)
    print()
        
def printMatrix(matrix):
    size = len(matrix)
    
    for i in range(size):
        for j in range(size):
            print(matrix[i][j], end=" ")
        print()
    print()