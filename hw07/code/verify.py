import numpy as np
import sys

f = open(sys.argv[1], 'r')
f.readline()
A = []
for line in f:
    line = line[:-1]
    x = [float(x) for x in line.split(' ')]
    A.append(x)
f.close()

A = np.array(A, np.float64)

[eig,w] = np.linalg.eig(A)
eig.sort()

print eig
