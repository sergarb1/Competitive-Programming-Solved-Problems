#!/usr/bin/python3
import sys

from heapq import merge

from collections import OrderedDict

from operator import itemgetter

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def distancia(x,y,a,b):
    return abs(a-x)+abs(b-y)

def buscarMejor(posTim):
    global rides
    mejor=99999999999999999
    pos=-1
    res=[]
    cont=500

    llegoAntes=-1
    llegoAntesMejor=-1
    resAntes=[]
    posAntes=-1
    for i in range(len(rides)):
        llegoAntes=-1
        #si nos da tiempo a llegar
        cuantoTardo=max(posTim[2] + distancia(posTim[0], posTim[1], rides[i][0], rides[i][1]),rides[i][4])
        if cuantoTardo<=rides[i][4]:
            llegoAntes=cuantoTardo

        cuantoTardo=cuantoTardo+ distancia(rides[i][2], rides[i][3], rides[i][0], rides[i][1])


        if(rides[i][5]>=cuantoTardo):
            #cont=cont-1
            #if cont==0:
            #    break
            if cuantoTardo<mejor:
                mejor=cuantoTardo
                res=rides[i]
                pos=i

            if llegoAntes!=-1:
                if llegoAntesMejor==-1 or llegoAntesMejor>cuantoTardo:
                    llegoAntesMejor=cuantoTardo
                    posAntes=i
                    resAntes=rides[i]

    if posAntes != -1 and (llegoAntesMejor-250<mejor):
        # Inhabilitamos la tupla
        rides[posAntes][5] = -1
        rides.pop(posAntes)
        return resAntes, llegoAntesMejor


    if pos != -1:
        # Inhabilitamos la tupla
        rides[pos][5] = -1
        rides.pop(pos)
        return res, mejor

    else:
        return [],-1

def imprimeResultado(c):
    for coche in c:
        linea=str(len(c[coche]))
        ride=c[coche]
        for i in ride:
            linea=linea+" "+str(i)

        print(linea)


def calcular():
    global R, C, F, N, B, T, rides

    coches={}
    #Estado inicial
    posTimCoches=[]
    for i in range(F):
        posTimCoches.append([0,0,0,i])
    numCoc=0
    for i in range(len(rides)):


        numCoc=0
        eprint(i)
        while (True):

            if numCoc>=F:
                break

            if posTimCoches[numCoc][3] in coches:

                tupla,tiempo=buscarMejor(posTimCoches[numCoc])
                if tiempo==-1:
                    numCoc=numCoc+1
                    continue

                coches[posTimCoches[numCoc][3]].append(tupla[6])
                posTimCoches[numCoc]=[tupla[2],tupla[3],tiempo,posTimCoches[numCoc][3]]

                def customKey(elemento):
                    return elemento[2]

                posTimCoches.sort(key=customKey)
                break
            else:
                tupla,tiempo=buscarMejor(posTimCoches[numCoc])
                if tiempo==-1:
                    numCoc=numCoc+1
                    continue

                coches[posTimCoches[numCoc][3]]=[tupla[6]]
                posTimCoches[numCoc]=[tupla[2],tupla[3],tiempo,posTimCoches[numCoc][3]]

                def customKey(elemento):
                    return elemento[2]
                posTimCoches.sort(key=customKey)
                break
            numCoc=numCoc+1


    imprimeResultado(coches)


def main():
    # Variables globales que necesitan ser escrita
    global R, C, F, N, B, T, rides

    rides=[ ]
    R, C, F, N, B, T = map(int, input().split())


    for i in range(N):
        a,b,x,y,f,s = map(int, input().split())
        rides.append([a,b,x,y,f,s,i])



#    def customKey(elemento):
#        return elemento[5]

    #rides.sort(key=customKey)
    #print(rides)

    calcular()


if __name__ == '__main__':
    main()