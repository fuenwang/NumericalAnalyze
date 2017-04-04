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

def ReadJson(f_name):
    f = open(f_name,'r')
    data = json.load(f)
    f.close()
    return data

[N, data] = ReadCSV('complexity.csv')
data = np.array(data)
N = np.array(N)

plt.figure()
plt.subplot('111')

plt.plot(N, data, 'r--', marker='o', label='iter_avg')
plt.plot(N, 10**(-8)*N**2, 'b--', marker='o', label='$N^2$')

plt.xscale('log')
plt.yscale('log')
#plt.xlim(10, 400)
#plt.xticks([10, 50, 100, 150])
plt.xlabel('N')
plt.ylabel('Time(s)')
plt.title('Average Iteration Runtime')
plt.legend(loc='upper left', fontsize='large')
#plt.show()
plt.savefig('complexity.pdf', dpi=300, bbox_inches='tight')
