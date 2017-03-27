from matplotlib import pyplot as plt
import json
import numpy as np
import csv


f = open('complexity.csv', 'r')
for i,line in enumerate(csv.reader(f)):
    if i == 0:
        N = [float(x) for x in line]
    elif i == 7:
        jacobi = [float(x) for x in line]
    elif i == 8:
        gauss = [float(x) for x in line]
    elif i == 9:
        sgs = [float(x) for x in line]
print N
print jacobi
print gauss
print sgs
N = np.array(N)
jacobi = np.array(jacobi)
gauss = np.array(gauss)
sgs = np.array(sgs)

plt.figure()
plt.subplot(1,1,1)

plt.plot(N, np.zeros(len(N)) + 1, 'r--', label='Y = 1')
plt.plot(N, gauss / sgs, 'b--', marker='o', label='Gauss-Seidel / SGS')

plt.xlabel('N')
plt.ylabel('Proportion')
plt.title('Proportion of total runtime')
plt.ylim([0, 2])
plt.xscale('log')
#plt.yscale('log')

plt.legend()
#plt.show()

plt.savefig('gauss_sgs_runtime.pdf', dpi=300, bbox_inches='tight')

