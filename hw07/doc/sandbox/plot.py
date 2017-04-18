import numpy as np
from matplotlib import pyplot as plt
import Parser

data1 = Parser.ReadCSV('iter_num_unshifted.csv')
data2 = Parser.ReadCSV('iter_avg_unshifted.csv')
data3 = data1[:,1] * data2[:,1]
#print data
N1 = data1[:, 0]
num1 = data3

data1 = Parser.ReadCSV('iter_num_shifted.csv')
data2 = Parser.ReadCSV('iter_avg_shifted.csv')
data3 = data1[:,1] * data2[:,1]

N2 = data1[:,0]
num2 = data3


plt.subplot('111')



plt.plot(N1, num1, 'r--', marker='o', label='EVqr')

plt.plot(N2, num2, 'b--', marker='o', label='EVqrShifted')

plt.plot(N1, 10**(-6) * N1**5, 'm--', marker='o', label='$N^5$')
plt.plot(N2, 10**(-8) * N2**4, 'y--', marker='o', label='$N^4$')

plt.title('Overall complexity')
plt.xlabel('N')
plt.ylabel('Time(s)')
plt.xscale('log')
plt.yscale('log')
plt.legend()
#plt.show()

plt.savefig('overall.pdf', dpi=300, bbox_inches='tight')
