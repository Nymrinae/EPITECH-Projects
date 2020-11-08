#!usr/bin/env python3

import sys
from maths import *
from errors import * 
from combinaisons import *

dices = list()

if (checkDices()):
    buildDicesList(dices)
    checkCombi(dices)