# 202unsold
Compute the probabilty to sell a $x jacket and $y trousers together and print:
- An array summing up the joint law (X, Y) and the marginal laws of X and Y
- An array summing up the law of Z
- Expected values and variances of X, Y and Z.

**Usage** <br>
```bash
./202unsold a b
    
    a: constant computed from the past results
    b: constant computed from the past results
```

**Output** <br>
```bash
------------------------------------------------------
        X=10    X=20    X=30    X=40    X=50    Y law
Y=10    0.100   0.080   0.060   0.040   0.020   0.300
Y=20    0.083   0.067   0.050   0.033   0.017   0.250
Y=30    0.067   0.053   0.040   0.027   0.013   0.200
Y=40    0.050   0.040   0.030   0.020   0.010   0.150
Y=50    0.033   0.027   0.020   0.013   0.007   0.100
X law   0.333   0.267   0.200   0.133   0.067   1
------------------------------------------------------
z        20      30      40      50      60      70      80      90      100     total
p(Z=z)   0.100   0.163   0.193    0.193   0.167  0.100   0.053   0.023   0.007   1
------------------------------------------------------
expected value of X:    23.3
variance of X:          155.6
expected value of Y:    25.0
variance of Y:          175.0
expected value of Z:    48.3
variance of Z:          330.6
```