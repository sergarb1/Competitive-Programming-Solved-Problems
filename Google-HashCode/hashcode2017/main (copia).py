#!/usr/bin/python3
import random
import json
import sys
import os
from heapq import merge

#devcuelve mejor cache para endpoint de ese video y que quepa

def obtenerMejorCacheYCabe(nEnd,nVid):
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo, dicResultado

    resultado=-1
    mejorLat=9999

    for i in range(C):
        if(cuantoLibre(i)>int(videos[nVid])):
            if i in dicEndCache:
                if nEnd in dicEndCache[i]:
                    lat=dicEndCache[i][nEnd]
                    if lat<mejorLat:
                        mejorLat=lat
                        resultado=i


    if resultado==-1:
        return None
    else:
        return resultado


#devuelve el numero de video mejor para ese endpoint

def obtenerMejor(nEnd):
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo, dicResultado

    max=-1
    maxN=-1

    if nEnd in dicEndVideo:
        for j in dicEndVideo[nEnd]:
            if int(videos[j])>X:
                continue
            tam=int(videos[j])*int(dicEndVideo[nEnd][j])
            #print("Para endpoint "+str(nEnd)+" video  "+str(j)+ " con tam "+str(tam))
            if(tam>max):
                max=tam
                maxN=j

        if max>-1:
            return maxN
        else:
            return None


    else:
        return None



def primeroMaximo():
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo, dicResultado


    for j in range(E):
        while True:
            laMejor=obtenerMejor(j)
            #print("El mejor para "+str(j)+" es "+str(laMejor))
            if laMejor is None:
                break

            #escoger cache mas rapida disponible para ese endpoint y que quepa

            nCache=obtenerMejorCacheYCabe(j,laMejor)

            if nCache==None:
                break
            else:
                if nCache in dicResultado:
                    if laMejor not in dicResultado[nCache]:
                        dicResultado[nCache].append(laMejor)
                else:
                    dicResultado[nCache] = [laMejor]

            #cargarse la request
            dicEndVideo[j].pop(laMejor, None)



def cuantoLibre(numCache):
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo, dicResultado

    if numCache not in dicResultado:
        return X

    lista=dicResultado[numCache]

    res=0
    for i in range(len(lista)):
        res=res+int(videos[lista[i]])


    return X-res



def primeroCabe():
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo, dicResultado

    for i in range(V):
        for j in range(C):
            if cuantoLibre(j)>int(videos[i]):
                if j  in dicResultado:
                    if i not in dicResultado[j]:
                        dicResultado[j].append(i)
                else:
                    dicResultado[j]=[i]



#main
def main():

    #Variables globales que necesitan ser escrita
    global V,E,R,C,X,videos,dicEndCache,dicEndCentral,dicEndVideo,dicResultado

    V, E, R, C, X=map(int, input().split())

    videos=(input().split())


    dicResultado={}
    #hola google

    #Aqui las latencias y la latencia del endpoint sevidor
    #Latencia de el endpoint con los servidores cache que tengan (pueden ser 0)
    dicEndCache={}
    #Latencia endpoint con servidor
    dicEndCentral={}
    #Diccionario que guarda numero de peticiones desde un endpoint  de un video
    dicEndVideo={}


    for i in range(E):
        LCentral, Ncaches = map(int, input().split())
        dicEndCache[i]={}

        dicEndCentral[i]=LCentral
        for j in range(Ncaches):
            Ecache, Lcache = map(int, input().split())
            dicEndCache[i][Ecache]=Lcache

    #Request
    for i in range(R):
        Nvideo, Evideo, Nrequest = map(int, input().split())
        if Evideo in dicEndVideo:
            if Nvideo in dicEndVideo[Evideo]:
                dicEndVideo[Evideo][Nvideo] =dicEndVideo[Evideo][Nvideo]+ Nrequest
            else:
                dicEndVideo[Evideo][Nvideo]=Nrequest
        else:
            dicEndVideo[Evideo]={}
            dicEndVideo[Evideo][Nvideo] = Nrequest
    '''
    print("Endpoints to cache")
    print(dicEndCache)
    print("Endpoints to central")

    print(dicEndCentral)
    print("Endpoins and videos")

    print (dicEndVideo)

    '''
    primeroMaximo()
    primeroCabe()

    print(len(dicResultado))
    for i in dicResultado:
        cadena=str(i)
        for j in range(len(dicResultado[i])):
            cadena=cadena+" "+str(dicResultado[i][j])

        print(cadena)




if __name__ == "__main__":
    # execute only if run as a script
    main()