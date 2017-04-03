import csv
import json
import numpy as np
from matplotlib import pyplot as plt

def ReadCSV(f_name):
    data = []
    f = open(f_name, 'r')
    reader = csv.reader(f)
    for one in reader:
        one = [float(x) for x in one]
        data.append(one)
    f.close()
    return data

[N1, ja, gs, sgs, cg] = ReadCSV('iter.csv')

N1 = np.array(N1)

plt.figure()
plt.subplot('111')

plt.plot(N1, ja, 'g--', marker='o', label='Jacobi')
plt.plot(N1, gs, 'm--', marker='o', label='Gauss-Seidel')
plt.plot(N1, sgs, 'b--', marker='o', label='SGS')
plt.plot(N1, cg, 'r--', marker='o', label='CG')

plt.xscale('log')
plt.yscale('log')
plt.xlabel('N')
plt.ylabel('Iteration')
plt.title('Iterative Methods Comparison')
plt.legend()
#plt.show()
plt.savefig('iter.pdf', dpi=300, bbox_inches='tight')
