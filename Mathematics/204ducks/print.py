from maths import *

def avg_rt(a):
    res = espf(a)
    sec = res % 1 * 60
    print("%dm %ds" %(res, round(sec)))

def sd(a):
    et = ecf(a)
    print("%0.3f" %(et))

def ducks_cb(p, a):
    t = get_time(p, a)
    minutes = t / 60
    s1 = t % 60 / 10
    s2 = (t % 10)
    print("%dm %d%ds" %(minutes, s1, round(s2)))

def ducks(a):
    print("Average return time: ", end='')
    avg_rt(a)
    print("Standard deviation: ", end='')
    sd(a)
    print("Time after which 50% of the ducks are back: ", end='')
    ducks_cb(0.5, a)
    print("Time after which 99% of the ducks are back: ", end='')
    ducks_cb(0.99, a)
    print("Percentage of ducks back after 1 minute: %0.1f%%" %(ducks_timing(a, 1)))
    print("Percentage of ducks back after 2 minutes: %0.1f%%" %(ducks_timing(a, 2)))