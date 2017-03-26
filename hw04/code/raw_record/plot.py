from matplotlib import pyplot as plt
import json
import numpy as np


f = open('sgs_iter.json', 'r')
data = json.load(f)
f.close()

x = np.arange(0, len(data)) + 1
plt.figure()
plt.subplot(1,1,1)
plt.plot(x, data, 'b', label='iter time(s)')
plt.title('Runtime of each iteration')
plt.xlabel('iter')
plt.ylabel('Time(s)')
plt.legend()
#plt.show()

plt.savefig('sgs_iter.pdf', dpi=300, bbox_inches='tight')

