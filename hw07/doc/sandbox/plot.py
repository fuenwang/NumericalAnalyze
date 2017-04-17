import numpy as np
from matplotlib import pyplot as plt
import Parser


data = Parser.ReadCSV('iter_num_shifted.csv')
#print data
N = data[:, 0]
num = data[:, 1]

plt.subplot('111')
#plt.tight_layout()

plt.title('Iteration num of EVqrShifted')
#plt.title('iter_avg of EVqrShifted')
plt.plot(N, num, 'r--', marker='o', label='iter_num')
plt.plot(N, N, 'b--', marker='o', label='$N$')
plt.xlabel('N')
plt.ylabel('Number')
plt.legend()
plt.xscale('log')
plt.yscale('log')
'''
plt.subplot('212')
plt.tight_layout()


plt.title('Iteration number of EVqr(log scale)')
plt.plot(N, num, 'r--', marker='o', label='iter number')
plt.plot(N, N**2, 'b--', marker='o', label='$N^2$')
plt.xlabel('N')
plt.ylabel('Number')
plt.legend()
plt.xscale('log')
plt.yscale('log')
'''
#plt.show()

plt.savefig('iter_num_shifted.pdf', dpi=300, bbox_inches='tight')
