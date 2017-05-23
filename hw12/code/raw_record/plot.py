import csv
import Parser
import numpy as np
from matplotlib import pyplot as plt

M = Parser.ReadJson('trap_001.json')
h = 0.01

l = M.shape[0]
x = (np.arange(l) + 1) * h

plt.figure()
plt.title('Trapezoidal(h = 0.01)')
plt.plot(x, M[:, 0], 'r', label = 'v1')
plt.plot(x, M[:, 1], 'g', label = 'v2')
plt.plot(x, M[:, 2], 'b', label = '$i_L$')

plt.xlabel('time')
plt.ylabel('Volt, Amp')
plt.legend()
#plt.show()
plt.savefig('trap_001.pdf', dpi=300, bbox_inches='tight')
