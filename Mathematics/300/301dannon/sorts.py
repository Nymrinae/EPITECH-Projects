import sys
from errors import *

def printNbElements():
    numberListLen = len(readFile(sys.argv[1]))

    print("%d element" %(numberListLen)) if numberListLen == 1 else print("%d elements" %(numberListLen))

def selectionSort():
    c = 0
    numberList = readFile(sys.argv[1])
    for i in range(len(numberList)):
        min = i
        for j in range(i + 1, len(numberList)):
            c += 1
            if numberList[min] > numberList[j]: 
                min = j
        numberList[i], numberList[min] = numberList[min], numberList[i]
    print("Selection sort: %d comparisons" %(c))

def insertionSort():
    c = 0
    numberList = readFile(sys.argv[1])
    for i in range(1, len(numberList)):
        key = numberList[i]
        for j in range(i):
            if (numberList[j] > numberList[i]):
                c += 1
    print("Insertion sort: %d comparisons" %(c))

def bubbleSort():
    c = 0
    numberList = readFile(sys.argv[1])
    n = len(numberList) 
    for i in range(n): 
        for j in range(0, n-i-1):
            c += 1
            if numberList[j] > numberList[j + 1]:
                numberList[j], numberList[j + 1] = numberList[j + 1], numberList[j]
    print("Bubble sort: %d comparisons" %(c))

def quickSort():
    """ c = 0
    numberList = readFile(sys.argv[1]) """
    print("Quicksort: %d comparisons" %(0))
    
def mergeSort():
    print("Merge sort: %d comparisons" %(0))