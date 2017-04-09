import numpy as np
import scipy.sparse.linalg
import json
import time

cg = scipy.sparse.linalg.cg

def Array(data):
    return np.array(data, dtype=np.float64)

def ReadMat(f_name):
    f = open(f_name, 'r')
    data = json.load(f);
    f.close()
    data = np.array(data, dtype=np.float64)
    return data


if __name__ == "__main__":
    #t = ReadMat("raw_record/A.json")
    #w,v = np.linalg.eig(t)
    #w.sort()
    #print w
    #print np.max(w)
    #print np.min(w)
    '''
    a = time.time()
    Q,R = np.linalg.qr(t)
    print Q
    print R

    print time.time() - a
    '''
    A = ReadMat("raw_record/A.json")
    B = ReadMat("raw_record/B.json")

    print type(Array([1,2,3])[0])
    x = np.zeros(len(B), dtype=np.float64)
    x,_ = cg(A,B,x, tol=1e-9, maxiter=10000)
    print '%.9lf'%x[0]
    #A_inv = np.linalg.pinv(A)
    #x = np.dot(A_inv, B)
    #for i in range(len(x)):
    #    print '%.9lf'%x[i]
