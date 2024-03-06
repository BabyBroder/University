import numpy as np
from time import time

fi = open('array.in', 'r')
fo = open('TimeExecution.out', 'a+')
lst = np.array(fi.readlines())
for i in range(10):
    a = np.copy(lst[i].split(' '))[:-1].astype(float)
    start = time()
    a = np.sort(a)
    elapse_time = round((time() - start) * 1000)
    fo.write("Time of sorting array " + str(i+1) + " using Library Python: " + str(elapse_time)+ " ms" +'\n')
    f=open('testLibraryPython.out','a')
    np.savetxt(f, a, fmt='%d', newline=" ")
    f.write("\n")
    f.close()

fi.close()