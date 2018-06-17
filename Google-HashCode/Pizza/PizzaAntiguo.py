#!/usr/bin/python3
import sys
import numpy as np
import json
from heapq import merge
from copy import copy, deepcopy

#HAY QUE USAR GLOBAL PARA MODIFICAR VARIABLES GLOBALES!!!!



with open('dicCuadrados.json') as data_file:
    diccionarioCuadrados = json.load(data_file)



slices=[]
slicesHorizontal=[]
slicesHorizontalMarcar=[]
slicesVertical=[]
slicesVerticalMarcar=[]
pizza=[]
R=0
C=0
L=0
H=0


#Funcion que dice si una cortada es valida
def cortar(iniX,iniY,finX,finY):
    tam=(finX-iniX+1)*(finY-iniY+1)
    if(tam>H):
        return -1

    t=0
    m=0

    for i in range(iniY,finY+1):
        for j in range(iniX,finX+1):
            if(pizza[i][j]=='T'):
                t=t+1
            else:
                m=m+1
            if m>=L and t>=L:
                return tam
    return -1


def disponible(p,actualC,actualR,destinoC,destinoR):
    for i in range(actualR,destinoR+1):
        for j in range(actualC,destinoC+1):
            if p[i][j]!=0:
                return False

    return True


def marcar(p, actualC, actualR, destinoC, destinoR):
    for i in range(actualR, destinoR + 1):
        for j in range(actualC, destinoC+1):
            p[i][j]=1

    return p

#Cortamos pizza en horizontal marcar
def busquedaHorizontalMarcar(p):
    pizzaN=p
    hN=H
    slicesHorizontalMarcar=[]

    actualC=0
    actualR=0
    while hN>=2*L:
        while actualR<R:
            destinoC=min(actualC+hN-1,C-1)
            if(disponible(pizzaN,actualC,actualR,destinoC,actualR) and cortar(actualC,actualR,destinoC,actualR)>0):
                slicesHorizontalMarcar.append([actualR,actualC,actualR,destinoC])
                pizzaN=marcar(pizzaN,actualC,actualR,destinoC,actualR)
                actualC=destinoC+1
            else:
                actualC=actualC+1

            if actualC>=C-1:
                actualC=0
                actualR=actualR+1


        hN=hN-1
    return pizzaN,slicesHorizontalMarcar

#Cortamos pizza en vertical marcar
def busquedaVerticalMarcar(p):
    pizzaN=p
    hN=H
    slicesVerticalMarcar=[]

    actualC=0
    actualR=0
    while hN>=2*L:
        while actualC < C:
            destinoR = min(actualR + H - 1, R - 1)
            if (disponible(pizzaN,actualC,actualR,actualC,destinoR) and cortar(actualC, actualR, actualC, destinoR) > 0):
                slicesVerticalMarcar.append([actualR, actualC, destinoR, actualC])
                pizzaN = marcar(pizzaN, actualC, actualR, actualC, destinoR)
                actualR = destinoR + 1
            else:
                actualR = actualR + 1

            if actualR >= R - 1:
                actualR = 0
                actualC = actualC + 1

        hN=hN-1
    return pizzaN,slicesVerticalMarcar




#Cortamos pizza en horizontal
def busquedaHorizontal():

    slicesHorizontal=[]
    actualC=0
    actualR=0
    while actualR<R:
        destinoC=min(actualC+H-1,C-1)
        if(cortar(actualC,actualR,destinoC,actualR)>0):
            slicesHorizontal.append([actualR,actualC,actualR,destinoC])

            actualC=destinoC+1
        else:
            actualC=actualC+1

        if actualC>=C-1:
            actualC=0
            actualR=actualR+1
    return slicesHorizontal


# Cortamos pizza en vertical
def busquedaVertical():
    slicesVertical=[]
    actualC = 0
    actualR = 0
    while actualC < C:
        destinoR = min(actualR + H - 1, R - 1)
        if (cortar(actualC, actualR, actualC, destinoR) > 0):
            slicesVertical.append([actualR, actualC, destinoR, actualC])

            actualR = destinoR + 1
        else:
            actualR=actualR+1

        if actualR >= R - 1:
            actualR = 0
            actualC = actualC + 1
    return slicesVertical

def busquedaMarcarCuadrado(p,tamR,tamC):
    pizzaN = p
    slicesCMarcar = []

    actualC = 0
    actualR = 0
    while actualR < R:
        destinoC = min(actualC + tamC - 1, C - 1)
        destinoR = min(actualR + tamR - 1, R - 1)
        if (disponible(pizzaN, actualC, actualR, destinoC, destinoR) and cortar(actualC, actualR, destinoC,
                                                                               destinoR) > 0):
            slicesCMarcar.append([actualR, actualC, destinoR, destinoC])
            pizzaN = marcar(pizzaN, actualC, actualR, destinoC, destinoR)
            actualC = destinoC + 1
        else:
            actualC = actualC + 1

        if actualC >= C - 1:
            actualC = 0
            actualR = actualR + 1

    return pizzaN, slicesCMarcar


# Buscamos cuadrados de tam t
def busquedaCuadrado(p,t):
    pizzaN=p
    if(t<4):
        return pizzaN,[]
    t = str(t)

    slices=[]

    for cuad in diccionarioCuadrados[t]:
        sys.stderr.write(str(cuad)+"\n")
        pizzaN,s=busquedaMarcarCuadrado(p,cuad[0],cuad[1])
        slices=list(merge(slices,s))

    return pizzaN,slices


# Buscamos cuadrados de tam t pero solo del mayor
def busquedaCuadradoMayor(p,t):
    pizzaN=p
    if(t<4):
        return pizzaN,[]
    t = str(t)


    slices=[]

    mayorCuad=[]
    area=0
    for cuad in diccionarioCuadrados[t]:
        nArea=cuad[0]*cuad[1]
        if(area<nArea):
            area=nArea
            mayorCuad=cuad[:]

    sys.stderr.write(str(mayorCuad)+"\n")
    pizzaN,s=busquedaMarcarCuadrado(p,mayorCuad[0],mayorCuad[1])
    slices=list(merge(slices,s))

    return pizzaN,slices



#calculamos el valor de cada pizza
def fitnessPizza(misSlices):
    tam=0
    for entrada in misSlices:
        tamTmp=(entrada[2]-entrada[0]+1)*(entrada[3]-entrada[1]+1)
        tam=tam+tamTmp

    return tam


#main
def main():
    #Variables globales que necesitan ser escrita
    global R,C,L,H,pizza
    #Soluciones y solucion mejor
    soluciones=[]
    solBest=[]

    R,C,L,H=map(int, input().split())

    pizza = []
    slices=[]
    for _ in range(R):
        pizza.append(input())

    #Buscamos la pizza en horizontal
    slicesHorizontal=busquedaHorizontal()
    soluciones.append(slicesHorizontal)


    #Buscamos la pizza en vertical
    slicesVertical=busquedaVertical()
    soluciones.append(slicesVertical)

    #Buscamos la pista marcando HV
    p=np.zeros((R, C))
    p,slicesHorizontalMarcar=busquedaHorizontalMarcar(p)
    p,slicesVerticalMarcar=busquedaVerticalMarcar(p)

    slicesMarcarHV = list(merge(slicesHorizontalMarcar, slicesVerticalMarcar))

    soluciones.append(slicesMarcarHV)

    # Buscamos la pista marcando VH
    p = np.zeros((R, C))

    p,slicesVerticalMarcar=busquedaVerticalMarcar(p)
    p,slicesHorizontalMarcar=busquedaHorizontalMarcar(p)

    slicesMarcarVH = list(merge(slicesHorizontalMarcar, slicesVerticalMarcar))

    soluciones.append(slicesMarcarVH)


    # Buscamos la pista marcando cuadrados segun lista
    p = np.zeros((R, C))
    slicesResultCuadrados=[]
    slicesResultCuadradosFinal=[]
    for i in range(H, 3, -1):
        p,slicesCuadrados=busquedaCuadrado(p,i)
        slicesResultCuadrados=list(merge(slicesResultCuadrados,slicesCuadrados))
        mensaje="Row "+str(R)+ " col "+str(C)+" probando cuadrado "+str(i)+"\n"
        sys.stderr.write(mensaje)

    p2 = deepcopy(p)

    p,sTempH1=busquedaHorizontalMarcar(p)
    p,sTempV1=busquedaVerticalMarcar(p)
    sTemp1=list(merge(sTempV1,sTempH1))
    sTemp1=list(merge(sTemp1,slicesResultCuadrados))



    p2,sTempV2=busquedaVerticalMarcar(p2)
    p2,sTempH2=busquedaHorizontalMarcar(p2)
    sTemp2=list(merge(sTempV2,sTempH2))
    sTemp2=list(merge(sTemp2,slicesResultCuadrados))

    mensaje = "S1 " + str(fitnessPizza(sTemp1)) + " S2 " + str(fitnessPizza(sTemp2))+"\n"
    sys.stderr.write(mensaje)

    if(fitnessPizza(sTemp1)>fitnessPizza(sTemp2)):
        slicesResultCuadradosFinal=sTemp1
    else:
        slicesResultCuadradosFinal = sTemp2

    soluciones.append(slicesResultCuadradosFinal)


    #Como el de antes, pero en lugar de todos cuadrados solo el mayor

    p = np.zeros((R, C))
    slicesResultCuadradosMayor=[]
    slicesResultCuadradosMayorFinal=[]
    for i in range(H, 3, -1):
        p,slicesCuadradosMayor=busquedaCuadradoMayor(p,i)
        slicesResultCuadradosMayor=list(merge(slicesResultCuadradosMayor,slicesCuadradosMayor))
        mensaje="Row "+str(R)+ " col "+str(C)+" probando cuadrado Mayor de "+str(i)+"\n"
        sys.stderr.write(mensaje)

    p2 = deepcopy(p)


    p,sTempH1=busquedaHorizontalMarcar(p)
    p,sTempV1=busquedaVerticalMarcar(p)
    sTemp1=list(merge(sTempV1,sTempH1))
    sTemp1=list(merge(sTemp1,slicesResultCuadradosMayor))



    p2,sTempV2=busquedaVerticalMarcar(p2)
    p2,sTempH2=busquedaHorizontalMarcar(p2)
    sTemp2=list(merge(sTempV2,sTempH2))
    sTemp2=list(merge(sTemp2,slicesResultCuadradosMayor))

    mensaje = "S1 M " + str(fitnessPizza(sTemp1)) + " S2 M " + str(fitnessPizza(sTemp2))+"\n"
    sys.stderr.write(mensaje)

    if(fitnessPizza(sTemp1)>fitnessPizza(sTemp2)):
        slicesResultCuadradosMayorFinal=sTemp1
    else:
        slicesResultCuadradosMayorFinal = sTemp2

    soluciones.append(slicesResultCuadradosMayorFinal)



    #Obtener la mejor solucion de las buscadas
    maxFitness=0
    for sol in soluciones:
        fit=fitnessPizza(sol)
        if(fit>maxFitness):
            maxFitness=fit
            solBest=sol


    #Imprimimos el mejor resultado
    #print(maxFitness)
    mensaje = str(maxFitness) + "\n"
    sys.stderr.write(mensaje)


    print(len(solBest))
    for x in solBest:
        print(str(x[0])+" "+str(x[1])+" "+str(x[2])+" "+str(x[3]))

if __name__ == "__main__":
    # execute only if run as a script
    main()
