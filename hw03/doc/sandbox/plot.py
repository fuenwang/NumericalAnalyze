from matplotlib import pyplot as plt
import numpy as np
import csv

N = []
run = []
model = []
LU = []
FWD = []
BCK =[]

tmp = [N, run, model, LU, FWD, BCK]
with open('data.csv', 'r') as f:
    reader = csv.reader(f)
    for i,line in enumerate(reader):
        line.pop(0)
        tmp[i] = [float(x) for x in line]
        tmp[i] = np.array(tmp[i], np.float64)

N, run, model, LU, FWD, BCK = tmp

plt.figure()

plt.subplot('111')
plt.plot(N, N**2, 'r--', marker='o', label='$N^2$')
plt.plot(N, model, 'b--', marker='o', label='PROBLEM')
#plt.plot(N, FWD, 'b--', marker='o', label='FWD(s)')
#plt.plot(N, BCK, 'g--', marker='o', label='BCK(s)')

plt.xscale('log')
plt.yscale('log')
plt.xlabel('N')
plt.ylabel('Time(s)')
plt.legend()
#plt.show()
plt.savefig('problem.pdf', dpi=400, bbox_inches='tight')
