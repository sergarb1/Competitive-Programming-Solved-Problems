import sys
import numpy as np
def marcar(p, actualC, actualR, destinoC, destinoR):
    for i in range(actualR, destinoR + 1):
        for j in range(actualC, destinoC+1):
            p[i][j]=1

    return p


R, C, L, H = map(int, input().split())

tamCortes = min(int(min(R, C) / 2), 10)
pizza = []
for _ in range(R):
    pizza.append(input())


#Leemos y marcamos


p = np.zeros((R, C))

f = open(sys.argv[1], 'r')

N = int(f.readline())
solFich = []
for line in f:
    line = line.split()
    lineN = []
    for x in line:
        lineN.append(int(x))
    solFich.append(lineN)
    p=marcar(p,lineN[1],lineN[0],lineN[3],lineN[2])

for i in range(len(pizza)):
    cad = ""
    for j in range(len(pizza[0])):

        if p[i][j]==1:
            cad=cad+"X"
        else:
            cad=cad+pizza[i][j]
    print (cad)


