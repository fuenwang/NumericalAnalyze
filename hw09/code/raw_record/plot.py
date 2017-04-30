import numpy as np
from matplotlib import pyplot as plt
import json

def ReadJson(f_n):
    f = open(f_n, 'r')
    data = np.array(json.load(f), np.float64)
    f.close()

    return data

index = '21'

X = ReadJson('X%s.json'%index)
Y = ReadJson('Y%s.json'%index)
XO = ReadJson('XO.json')
YO = ReadJson('YO.json')
XS = ReadJson('XS%s.json'%index)
YS = ReadJson('YS%s.json'%index)

plt.subplot('111')


plt.plot(X, Y, 'r', label='f%s.dat'%index)
plt.plot(XO, YO, 'b', label='f301.dat')
plt.plot(XS, YS, 'og', label='support pts')


plt.xlabel('X')
plt.ylabel('Y')
plt.title('f%s.dat'%index)
plt.legend()
plt.show()
#plt.savefig('f%s.pdf'%index, dpi=300, bbox_inches='tight')
