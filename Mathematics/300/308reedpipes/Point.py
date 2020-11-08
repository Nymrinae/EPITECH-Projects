#!/bin/python3

from Error import error

h = 5

class Point:
	def __init__(self, x, y):
		self.x = x
		self.y = y
		self.F = 0

	def setF(self, idx, points):
		self.F = (points[idx + 1].y - self.y) / h - (self.y - points[idx - 1].y) / h

def check_points(points):
	for r in points:
		if r.y <= 0:
			error("Y is neg")

def print_points(points):
	for p in points:
		print("X=%.4f  Y=%.4f  F=%.4f" % (p.x, p.y, p.F))
