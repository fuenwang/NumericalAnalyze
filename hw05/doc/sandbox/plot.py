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

[N1, _, _, _, T1] = ReadCSV('LU.csv')
[N2, _, _, _, _, T2, _] = ReadCSV('cg.csv')

N1 = np.array(N1)
N2 = np.array(N2)

plt.figure()
plt.subplot('111')

plt.plot(N1, T1, 'r--', marker='o', label='LU')

plt.plot(N2, T2, 'b--', marker='o', label='CG')

plt.plot(N1, 1e-5*N1**3, 'g--', marker='o', label='$N^3$')
#plt.plot(N2, N2**2, 'p--', marker='o', label='$N^2$')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('N')
plt.ylabel('Time(s)')
plt.title('CG vs LU')
plt.legend()
#plt.show()
plt.savefig('cg_vs_lu.pdf', dpi=300, bbox_inches='tight')
