from threading import *
from numpy import *
import timeit
global result 
global execucoes
execucoes = 5
result = list()

def calcpi(numTermos):
    pi = 0
    for n in range(0,numTermos, 1):
        pi += pow(-1, n) / (2 * n + 1)
    pi *= 4
    double(pi)
    print(f"{pi}")
    result.append(pi)


soma =0
numTermos = int(input("->"))
for i in range(0,execucoes):
    inicio = timeit.default_timer()
    calcpi(numTermos)
    fim = timeit.default_timer() - inicio
    print(fim,"sec")

    
    
    
    
    
    
    
    
"""thread = Thread(target=calcpi, args=(500000, ))
    
    thread2.start()
    thread.start()
    
thread.join()

for i in range(0,len(result)):
    soma += result[i]
print(f"Threads finlizadas...saindo \n{soma}   {len(result)}")

"""