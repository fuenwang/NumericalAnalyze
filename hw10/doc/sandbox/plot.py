from matplotlib import pyplot as plt
import Parser
import numpy as np

data = Parser.ReadCSV('error.csv')
#print data

#data = data.T
print data
plt.subplot('111')

plt.yscale('log')
plt.xscale('log')
plt.xlabel('# of subintervals')
plt.ylabel('Error')
plt.title('Error vs Subintervals')

#plt.ylim([0, 1e-2])

x = np.array([1, 2, 3, 4, 6])


plt.plot(x, data[0,:], 'r--', marker='o', label='12')
plt.plot(x, data[1,:], 'g--', marker='o', label='24')
plt.plot(x, data[2,:], 'b--', marker='o', label='48')
plt.plot(x, data[3,:], 'm--', marker='o', label='96')
plt.plot(x, data[4,:], 'y--', marker='o', label='192')
plt.plot(x, data[5,:], 'c--', marker='o', label='384')
plt.plot(x, data[6,:], 'k--', marker='o', label='768')
plt.plot(x, data[7,:], '--', color='#C34A2C', marker='o', label='1536')

'''
plt.plot(x, data[0,:], 'r--', marker='o', label='1-order')
plt.plot(x, data[1,:], 'g--', marker='o', label='2-order')
plt.plot(x, data[2,:], 'b--', marker='o', label='3-order')
plt.plot(x, data[3,:], 'c--', marker='o', label='4-order')
plt.plot(x, data[4,:], 'm--', marker='o', label='6-order')
'''
plt.legend()
#plt.savefig('error2.pdf', dpi=300, bbox_inches='tight')
plt.show()
