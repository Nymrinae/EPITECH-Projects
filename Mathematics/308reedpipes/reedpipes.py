#!/bin/python3

from Point import *
from Error import error
from Inverse import resolve

def initF(points):
	for idx in range(1, 4):
		points[idx].setF(idx, points)

def initR(points):
	R = [[0 for i in range(5)] for j in range(5)]
	R[0][0] = 1
	R[4][4] = 1
	for i in range(1, 4):
		R[i][i] = (h + h) / 3
	for i in range(1, 4):
		R[i][i + 1] = h / 6
	for i in range(1, 4):
		R[i][i - 1] = h / 6
	return R

def columnM(points, R):
	F = [p.F for p in points]
	resolve(R, F)
	return F

def columnCC2(points, M):
	C = [0 for i in range(4)]
	C2 = [0 for i in range(4)]
	for idx in range(4):
		C[idx] = ((points[idx + 1].y - points[idx].y) / h) - (h / 6) * (M[idx + 1] - M[idx])
		C2[idx] = points[idx].y - M[idx] * ((h * h) / 6)
	return (C, C2)

def printM(M):
	print("vector result: [", end='')
	for i in range(len(M)):
		if round(M[i], 1) == 0:
			print(0.0, end=', ' if i != 4 else '')
		else:
			print("%.1f" %(M[i]), end=', ' if i != 4 else '')
	print("]")

def interpolation(points, x, M, C, C2):
	for k in range(5):
		if points[k].x <= x and points[k + 1].x >= x:
			return (M[k] * (((points[k + 1].x - x) ** 3) / (6 * h))) + (M[k + 1] * (((x - points[k].x) ** 3) / (6 * h))) + (C[k] * (x - points[k].x)) + C2[k]
	return None

def print_res(points, n, M, C, C2):
	x = 0
	while (x <= 20.0):
		interp = interpolation(points, x, M, C, C2)
		if interp != None:
			print("abscissa: %.1f cm\tradius: %.1f cm" %(x, interp))
		x += (20.0 / (n - 1))
