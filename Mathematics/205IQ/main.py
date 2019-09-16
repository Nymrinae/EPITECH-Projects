#!/usr/bin/env python3

import sys
from print      import *
from functions  import *

list = init_list()

if (len(list) == 1 and list[0] == '-h'):
    help()
elif (len(list) < 2 or len(list) >= 5):
    err("The number of args must be between 3 and 5.\n./205IQ -h for more information.")

l = list[0]
if (l != 100):
    err("Mean value must be 100.")
o = list[1]

if (len(list) == 2):
    tab = density(l, o)
    print_tab(tab)

if (len(list) == 3):
    iq1 = list[2]
    if (iq1 < 0 or iq1 > 200):
        err("IQ1 should be between 0 and 200.")
    res = integrale(f, l, o, 0, iq1)
    print_inf_IQ(res, iq1)

if (len(list) == 4):
    iq1 = list[2]
    iq2 = list[3]
    if (iq1 < 0 or iq1 > 200 or iq2 < 0 or iq2 > 200):
        err("IQs should be between 0 and 200.")
    res = integrale(f, l, o, iq1, iq2)
    print_between_IQ(res, iq1, iq2)