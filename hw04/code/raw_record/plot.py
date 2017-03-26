from matplotlib import pyplot as plt
import json
import numpy as np


f = open('sgs_error1.json', 'r')
f2 = open('sgs_error2.json', 'r')
f3 = open('sgs_error3.json', 'r')
data1 = json.load(f)
data2 = json.load(f2)
data3 = json.load(f3)


x1 = np.arange(0, len(data1)) + 1
x2 = np.arange(0, len(data2)) + 1
x3 = np.arange(0, len(data3)) + 1
plt.figure()
plt.subplot(1,1,1)

plt.plot(x1, data1, 'b', label='Error_1', linewidth=3)
plt.plot(x2, data2, 'r', label='Error_2', linewidth=3)
plt.plot(x3, data3, 'g', label='Error_infinite', linewidth=3)

plt.xlabel('iter')
plt.ylabel('Error')
plt.title('Symmetric Gauss-Seidel Error')


plt.legend()
#plt.show()

plt.savefig('sgs_error.pdf', dpi=300, bbox_inches='tight')

