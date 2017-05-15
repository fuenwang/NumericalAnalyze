import csv
import Parser
import numpy as np

M1 = Parser.ReadJson('M1.json')
M2 = Parser.ReadJson('M2.json')


height = M1.shape[0]
M1 = np.flipud(M1)
f = open('M1.csv', 'w')
writer = csv.writer(f)
writer.writerow(['V', 'v1', 'v2', 'Id1', 'Id2', 'Id3', 'Id4', 'Ir'])
for i in range(height):
    writer.writerow(M1[i].tolist())
f.close()

height = M2.shape[0]
M2 = np.flipud(M2)
f = open('M2.csv', 'w')
writer = csv.writer(f)
writer.writerow(['V', 'v1', 'v2', 'Id1', 'Id2', 'Id3', 'Id4', 'Ir', 'Td1',  'Td2', 'Td3', 'Td4'])
for i in range(height):
    writer.writerow(M2[i].tolist())
f.close()
