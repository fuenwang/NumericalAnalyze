import numpy as np
import csv

from matplotlib import pyplot as plt

f_name = 'LU.csv'
N = []
val = []
with open(f_name,'r') as f:
    reader = csv.reader(f)
    for i,one in enumerate(reader):
        one.pop(0)
        for onee in one[1:]:
            if i==0:
                N.append(float(onee))
            elif i==1:
                val.append(float(onee))
N = np.array(N)
val = np.array(val)
print N
print val

fig = plt.figure()
plt.subplot('111')
plt.plot(np.log(N**3), np.log(val), marker='o', label='LU(s)')
plt.legend()
plt.xlabel('$log(N^3)$')
plt.ylabel('$log(LU)$')
#plt.title('FWD vs $N^2$')
#plt.show()
plt.savefig('LU.pdf', dpi=300, bbox_inches='tight')
