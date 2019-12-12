#!/usr/bin/env python3

import sys
from sorts import *
from errors import *

if not checkError():
    printNbElements()
    selectionSort()
    insertionSort()
    bubbleSort()
    quickSort()
    mergeSort()