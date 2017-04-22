import numpy as np
from matplotlib import pyplot as plt
import json

def ReadJson(f_n):
    f = open(f_n, 'r')
    data = np.array(json.load(f), np.float64)
    f.close()

    return data


X = ReadJson('X.json')
Y = ReadJson('Y.json')
XO = ReadJson('XO.json')
YO = ReadJson('YO.json')

plt.subplot('111')


plt.plot(X, Y, 'r')
plt.plot(XO, YO, 'b')

plt.show()
