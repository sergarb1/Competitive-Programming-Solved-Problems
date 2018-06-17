from heapq import merge
import json
from copy import copy, deepcopy


def unir(listaA,listaB):
    nuevaLista=[]

    for a in listaA:
        nuevaLista.append(a)
    for b in listaB:
        nuevaLista.append(b)

    return nuevaLista

dic={}

#No sacamos los de 1 porque ya sacamos las horizontales y verticales
for i in range(20,1,-1):
    for j in range(20,1,-1):

        num=int(i*j)
        if(num>1000):
            continue
        if num in dic:
            dic[num].append([i, j])
        else:
            dic[num]=[]
            dic[num].append([i,j])


for i in range(2,1000):

    if i-1 in dic and i in dic:
        dic[i]=list(unir(dic[i],dic[i-1]))

    if i-1 in dic and i not in dic:
        dic[i]=deepcopy(dic[i-1])


with open('dicCuadrados.json', 'w') as outfile:
    json.dump(dic, outfile)
