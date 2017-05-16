import csv
import Parser
import numpy as np
from matplotlib import pyplot as plt

M1 = Parser.ReadJson('M2.json')
#M2 = Parser.ReadJson('M2.json')
M1 = np.flipud(M1)

print M1.shape
M1[101:201, :] = M1[102:, :]

M1[:101, :] = np.flipud(M1[:101, :])

print M1[: , 0]
M1 = M1[:-1, :]

x = (M1[:, 0])

plt.figure(figsize=(15,8))
plt.subplot('111')
plt.title('Problem 2 voltage')
'''
plt.plot(x, M1[:, 3], 'ro', markersize = 6, label='$I_{d1}$')
plt.plot(x, M1[:, 4], 'go', markersize = 6, label='$I_{d2}$')
plt.plot(x, M1[:, 5], 'yo', markersize = 2, label='$I_{d3}$')
plt.plot(x, M1[:, 6], 'ko', markersize = 2, label='$I_{d4}$')

plt.plot(x, M1[:, 7], 'b', linewidth = 2, label='$I_{R}$')
'''
plt.plot(x, M1[:, 8], 'ro', markersize = 6, label='$T_{d1}$')
plt.plot(x, M1[:, 9], 'go', markersize = 6, label='$T_{d2}$')
plt.plot(x, M1[:, 10], 'yo', markersize = 2, label='$T_{d3}$')
plt.plot(x, M1[:, 11], 'ko', markersize = 2, label='$T_{d4}$')

plt.xlabel('V')
plt.ylabel('Temperature')
plt.legend(prop={'size':10})
#plt.show()
plt.savefig('M2_temp.pdf', dpi=300, bbox_inches='tight')
