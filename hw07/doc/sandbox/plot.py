import numpy as np
from matplotlib import pyplot as plt
import Parser

data = Parser.ReadCSV('eigen.csv')
N = data[:, 0]

El1 = data[:, 1]
El2 = data[:, 2]
El3 = data[:, 3]
Es1 = data[:, 4]
Es2 = data[:, 5]
Es3 = data[:, 6]
'''
plt.subplot('111')
plt.tight_layout()
plt.plot(N, El1, 'r--', marker='o', label='E_large_1')
plt.plot(N, El2, 'g--', marker='o', label='E_large_2')
plt.plot(N, El3, 'b--', marker='o', label='E_large_3')
plt.plot(N, 10*N**2, 'm--', marker='o', label='$N^2$')
plt.title('Eigenvalue(largest)')
plt.xlabel('N')
plt.ylabel('Value')
plt.xscale('log')
plt.yscale('log')
plt.legend()
'''

plt.subplot('111')
plt.tight_layout()
a = np.zeros(len(N)) + 0.5
plt.plot(N, Es1, 'r--', marker='o', label='E_small_1')
plt.plot(N, Es2, 'g--', marker='o', label='E_small_2')
plt.plot(N, Es3, 'b--', marker='o', label='E_small_3')
plt.plot(N, a, 'm--', label='y = 0.5')

plt.title('Eigenvalue(smallest)')
plt.xlabel('N')
plt.ylabel('Value')
plt.xscale('log')
plt.yscale('log')
plt.legend()


#plt.show()
plt.savefig('eigen_smallest.pdf', dpi=300, bbox_inches='tight')
