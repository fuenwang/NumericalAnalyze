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

data = ReadJson('error.json')
data = np.array(data)
x = np.arange(1, len(data)+1)

plt.figure()
plt.subplot('111')

plt.plot(x, data, 'r', label='Error')

plt.xscale('log')
plt.yscale('log')
plt.xlim(10, 400)
#plt.xticks([10, 50, 100, 150])
plt.xlabel('iter')
plt.ylabel('Error')
plt.title('Iteration Error')
plt.legend()
#plt.show()
plt.savefig('iter_error.pdf', dpi=300, bbox_inches='tight')
