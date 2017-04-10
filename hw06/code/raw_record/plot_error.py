import numpy as np
from Parser import *
from matplotlib import pyplot as plt

e1 = np.array(ReadJson('error_e1.json'))
e2 = np.array(ReadJson('error_e2.json'))
e3 = np.array(ReadJson('error_e3.json'))
e4 = np.array(ReadJson('error_e4.json'))
y = np.zeros(len(e4), np.float32) + 1e-9
it = np.arange(1, len(e4)+1)

plt.subplot('111')
plt.plot(it, e1, 'r', label='$\\epsilon_1$')
plt.plot(it, e2, 'g', label='$\\epsilon_2$')
plt.plot(it, e3, 'b', label='$\\epsilon_3$')
plt.plot(it, e4, 'm', label='$\\epsilon_4$')
plt.plot(it, y, 'y--', label='$y = 10^{-9}$')

plt.xlabel('iter')
plt.ylabel('Error')
plt.yscale('log')
#plt.xscale('log')
plt.legend()
plt.xlim([1, 1700])
plt.title('Error vs iter')
#plt.show()
plt.savefig('error_1234.pdf', dpi=300, bbox_inches='tight')
