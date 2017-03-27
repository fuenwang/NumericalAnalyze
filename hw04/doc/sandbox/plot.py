from matplotlib import pyplot as plt
import json
import numpy as np
import csv


f = open('complexity.csv', 'r')
for i,line in enumerate(csv.reader(f)):
    if i == 0:
        N = [float(x) for x in line]
    elif i == 1:
        jacobi = [float(x) for x in line]
    elif i == 2:
        gauss = [float(x) for x in line]
    elif i == 3:
        sgs = [float(x) for x in line]
print N
print jacobi
print gauss
print sgs
N = np.array(N)
plt.figure()
plt.subplot(1,1,1)

plt.plot(N, jacobi, 'b--', marker='o', label='Jacobi')
plt.plot(N, gauss, 'g--', marker='o', label='Gauss-Seidel')

plt.plot(N, sgs, 'r--', marker='o', label='Symmetric Gauss-Seidel')
#plt.plot(N, sgs, 'r--', marker='o', label='SGS')
plt.plot(N, (N**2) / 10000000, 'm--', marker='o', label='$10^{-7}*N^2$')

plt.xlabel('N')
plt.ylabel('Time(s)')
plt.title('Runtime of each iteration')

plt.xscale('log')
plt.yscale('log')

plt.legend()
#plt.show()

plt.savefig('complexity.pdf', dpi=300, bbox_inches='tight')

