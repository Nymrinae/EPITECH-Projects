#!/bin/python3

def opLine(matrice, vector, y1, y2, coef1 = 1, coef2 = 1):
	if coef1 != 0:
		matrice[y1] = [matrice[y1][i] * coef1 + matrice[y2][i] * coef2 for i in range(len(matrice))]
		vector[y1] = vector[y1] * coef1 + vector[y2] * coef2

def cleanLine(matrice, vector, xc, yc):
	coef = matrice[yc][xc]
	for y in range(len(matrice)):
		if y != yc:
			opLine(matrice, vector, y, yc, 1, -matrice[y][xc] / coef)

def resolve(matrice, vector):
	for x in range(len(matrice)):
		opLine(matrice, vector, x, -1, 1 / matrice[x][x], 0)
		cleanLine(matrice, vector, x, x)
