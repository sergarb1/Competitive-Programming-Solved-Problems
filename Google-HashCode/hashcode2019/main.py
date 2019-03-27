#!/usr/bin/python3
import sys

from heapq import merge

from collections import OrderedDict

from operator import itemgetter


from collections import OrderedDict
from operator import itemgetter    
from copy import copy, deepcopy
import sys
import random
import os
import json

def factor(f1,f2):
    #tags en comun
    tagComun=list(set(f1[3]).intersection(f2[3]))
    nTagComun=len(tagComun)
    #tags en f1 y no en f2
    tagsF1=list(set(f1[3])-set(f2[3]))
    nTagsF1=len(tagsF1)
    #tags en f1 y no en f2
    tagsF2=list(set(f2[3])-set(f1[3]))
    nTagsF2=len(tagsF2)

    #Obtenemos el menor
    res=nTagComun

    if nTagsF1 < res:
        res=nTagsF1
        
    if nTagsF2 < res:
        res=nTagsF2
        
    return res


def factorVertical(f1,f2):
    #tags en comun
    tagComun=list(set(f1[3]).intersection(f2[3]))
    nTagComun=len(tagComun)
    #Obtenemos el menor
    res=nTagComun

        
    return res


def unirListaUnica(a,b):
    mergedlist = list(set(a) & set(b))
    return mergedlist

def juntarV(lista):
    nuevaLV=[]
    i=0
    while(i<len(lista)):
        if(i+1<len(lista)):
            tagsUnicos=unirListaUnica(lista[i][3],lista[i+1][3])
            nuevaLV.append([str(lista[i][0])+" "+str(lista[i+1][0]),'H',len(tagsUnicos),tagsUnicos,False] )
        i=i+2
    return nuevaLV


'''
def obtenerResultado(lista):
    res=[]
    seleccionada=random.randint(0,len(lista)-1)
    res.append(lista[seleccionada])
    lista[seleccionada][4]=True
    while(len(res)<len(lista)):
        i=random.randint(0,len(lista)-1)
        if  lista[i][4]==True:
            continue

        lista[i][4]=True
        res.append(lista[i])

    res.reverse()
    return res
'''

def obtenerResultado(lista):
    actual=0

    res=[]
    gastadas=0
    maxComunes=-1
    maxI=0
    usadasI=0
    usadasJ=0

    #anayadimos la primera a res
    actual=0
    res.append(lista[actual])
    lista[actual][4]=True
    gastadas=1

    #Mientras no haya gastado todas
    while gastadas<len(lista):
        for i in range(len(lista)):
            #print( "HOLA "+str(len(lista))+ " " + str(gastadas))
            if lista[i][4]==True:
                continue
            usadasI=usadasI+1
            
            

            comunes=factor(lista[i],lista[actual])
            
            if comunes>maxComunes:
                maxComunes=comunes
                maxI=i
     
        #Sale del for
        lista[maxI][4]=True        
        
        res.append(lista[maxI])
        actual=maxI
        gastadas=gastadas+1
        maxComunes=-1

        '''if gastadas>600:
            gastadas=len(lista)
            break
        '''

    #Metemos los que falten sin asignar

    for i in range(len(lista)):
        if lista[i][4]==False:
            res.append(lista[i])

    return res



def obtenerResultadoVertical(lista):
    actual=0

    res=[]
    gastadas=0
    maxComunes=999999999
    maxI=0
    usadasI=0
    usadasJ=0


    #anayadimos la primera a res
    actual=0
    
    #Si no hay lista...
    if len(lista)==0:
        return []

    res.append(lista[actual])
    lista[actual][4]=True
    gastadas=1

    #Mientras no haya gastado todas
    while gastadas<len(lista):
        for i in range(len(lista)):
            #print( "HOLA "+str(len(lista))+ " " + str(gastadas))
            if lista[i][4]==True:
                continue
            usadasI=usadasI+1
            
            

            comunes=factor(lista[i],lista[actual])
            
            if comunes<maxComunes:
                maxComunes=comunes
                maxI=i
     
        #Sale del for
        lista[maxI][4]=True        
        
        res.append(lista[maxI])
        for j in range(len(lista)):
            if lista[j][4]==False:
                actual=j
            break

        gastadas=gastadas+1
        maxComunes=999999999

        '''if gastadas>600:
            gastadas=len(lista)
            break
        '''

    #Metemos los que falten sin asignar

    for i in range(len(lista)):
        if lista[i][4]==False:
            res.append(lista[i])

    return res


def main():
    # Variables globales que necesitan ser escrita
    global N
    global listaFotos
    global listaFotosV
    global listaFotosH
    global nuevasH

    N = int(input())

    listaFotos=[]
    listaFotosH=[]
    listaFotosV=[]
    nuevasH=[]
    for i in range(N):
        entrada=input().split()
        orienta=str(entrada[0])
        nTags=int(entrada[1])
        tags=entrada[2:]


        foto=[i,orienta,nTags,tags,False]
        listaFotos.append(foto)
        #print(str(foto[0]) + " " +str(foto[1]))
        #print(str(nTags))
        #print(str(tags))
    
    for j in range(len(listaFotos)):
        if(listaFotos[j][1]=='H'):
            listaFotosH.append(listaFotos[j])
        else:
            listaFotosV.append(listaFotos[j])

    #Barajamos las fotosVerticales
    #random.shuffle(listaFotosV)
    '''
    def funcionOrdenacion (dato):
        return len(dato[3])
    
    listaFotosV.sort(key = funcionOrdenacion) 
    tmp=[]
    i=0
    j=len(listaFotosV)-1
    while i<j:
        tmp.append(listaFotosV[i])
        tmp.append(listaFotosV[j])
        i=i+1
        j=j-1

    listaFotosV=tmp
    '''
    #IDEA CARLOS COMENTADA
    listaFotosV=obtenerResultadoVertical(listaFotosV)

    #fin de mezcla nteligente


    nuevasH=juntarV(listaFotosV)  
    resultado=obtenerResultado(listaFotosH+nuevasH)
    print(len(resultado))
    for j in range(len(resultado)):
        print(resultado[j][0])

'''     
    nuevasH=juntarV(listaFotosV)       
 
    print(str(len(listaFotosH)+len(nuevasH)))

    for j in range(len(nuevasH)):
        print(nuevasH[j][0])

    for j in range(len(listaFotosH)):
        print(listaFotosH[j][0])
'''
#Lanzamos el main

if __name__ == '__main__':
    main()