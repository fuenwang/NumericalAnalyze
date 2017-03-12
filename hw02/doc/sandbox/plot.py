import numpy as np
import csv

from matplotlib import pyplot as plt

f_name = 'Runtime.csv'
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

f_name = 'LU.csv'
N1 = []
val1 = []
with open(f_name,'r') as f:
    reader = csv.reader(f)
    for i,one in enumerate(reader):
        one.pop(0)
        for onee in one[1:]:
            if i==0:
                N1.append(float(onee))
            elif i==1:
                val1.append(float(onee))
N1 = np.array(N1)
val1 = np.array(val1)

print N
print val

fig = plt.figure()
plt.subplot('111')
plt.plot(np.log(N**3), np.log(val), 'b', marker='o', label='runtime(s)')
plt.plot(np.log(N**3), np.log(val1), 'r', marker='o', label='LU(s)')
plt.legend()
plt.xlabel('$log(N^3)$')
plt.ylabel('$log(time)$')
#plt.title('FWD vs $N^2$')
#plt.show()
plt.savefig('time.pdf', dpi=301, bbox_inches='tight')
