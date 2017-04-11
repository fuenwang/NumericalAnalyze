import numpy as np
from Parser import *
from matplotlib import pyplot as plt
import csv


mat = ReadCSV('iter_avg.csv')
print mat
N = mat[0, :]
N2 = N**2
pwr = mat[1, :]
ipwr = mat[2, :]
ipwrsht = mat[3, :]

plt.subplot('111')
plt.plot(N, pwr, 'r--', marker='o', label='EVpwr')
plt.plot(N, ipwr, 'g--', marker='o', label='EViPwr')
plt.plot(N, ipwrsht, 'b--', marker='o', label='EViPwrShft')
plt.plot(N, 10**(-7) * N2, 'm--', marker='o', label='$N^2$')

plt.xlabel('N')
plt.ylabel('Time(s)')
plt.yscale('log')
plt.xscale('log')
plt.legend()
plt.title('iter_avg vs N')
#plt.show()
plt.savefig('iter_avg.pdf', dpi=300, bbox_inches='tight')
