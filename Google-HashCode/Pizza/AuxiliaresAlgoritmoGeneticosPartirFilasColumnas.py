import sys
import numpy as np
import json
from heapq import merge
from copy import copy, deepcopy
import os



with open('dicCuadrados.json') as data_file:
    diccionarioCuadrados = json.load(data_file)

#Obtenemos el fitness del antiguo
def calcularMaximoAntiguo(nombreFich):

    if os.stat(nombreFich).st_size == 0:
        return 0
    else:

        f = open(nombreFich, 'r')
        N = int(f.readline())
        solFich=[]
        for line in f:
            line=line.split()
            lineN=[]
            for x in line:
                lineN.append(int(x))
            solFich.append(lineN)
        return(fitnessPizza(solFich))


#Escribimos el fichero con el resultado mejor nuevo
def actualizarMaximoAntiguo(nombreFich,solBest):
    f2 = open(nombreFich, "w") #sys.argv[1]
    print(len(solBest), file=f2)
    for x in solBest:
        print(str(x[0]) + " " + str(x[1]) + " " + str(x[2]) + " " + str(x[3]), file=f2)


#Elimina entradas duplicadas de una lista
def eliminarDuplicadosLista(l):
    return list(set(l))


#Funcion que dice si una cortada es valida
def cortar(pizza,iniX,iniY,finX,finY,H,L):
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

#Funcion que recibe un p(mapa de pizza), la pizza y su inicio y fin y datos necesarios
#Devuelve las cortadas que se han podido hacer en horizontal en las zonas sin marcar
#y el resultado de la marcacion
def busquedaHorizontalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H):
    pizzaN=p
    hN=H
    slicesHorizontalMarcar=[]

    actualC=Cini
    actualR=Rini
    while hN>=2*L:
        while actualR<Rfin:
            destinoC=min(actualC+hN-1,Cfin-1)
            if(disponible(pizzaN,actualC,actualR,destinoC,actualR) and cortar(pizza,actualC,actualR,destinoC,actualR,H,L)>0):
                slicesHorizontalMarcar.append([actualR,actualC,actualR,destinoC])
                pizzaN=marcar(pizzaN,actualC,actualR,destinoC,actualR)
                actualC=destinoC+1
            else:
                actualC=actualC+1

            if actualC>=Cfin-1:
                actualC=Cini
                actualR=actualR+1

        hN=hN-1
    return pizzaN,slicesHorizontalMarcar



#Funcion que recibe un p(mapa de pizza), la pizza y su inicio y fin y datos necesarios
#Devuelve las cortadas que se han podido hacer en horizontal en las zonas sin marcar
#y el resultado de la marcacion
def busquedaVerticalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H):
    pizzaN=p
    hN=H
    slicesVerticalMarcar=[]

    actualC=Cini
    actualR=Rini
    while hN>=2*L:
        while actualC < Cfin:
            destinoR = min(actualR + H - 1, Rfin - 1)
            if (disponible(pizzaN,actualC,actualR,actualC,destinoR) and cortar(pizza,actualC, actualR, actualC, destinoR,H,L) > 0):
                slicesVerticalMarcar.append([actualR, actualC, destinoR, actualC])
                pizzaN = marcar(pizzaN, actualC, actualR, actualC, destinoR)
                actualR = destinoR + 1
            else:
                actualR = actualR + 1

            if actualR >= Rfin - 1:
                actualR = Rini
                actualC = actualC + 1

        hN=hN-1
    return pizzaN,slicesVerticalMarcar



#Funcion que recibe un p(mapa de pizza), la pizza y su inicio y fin y datos necesarios
#Tambien recibe el tamanyo de los rectangulo a buscar
#Devuelve las cortadas que se han podido hacer con el rectangulo en las zonas sin marcar
#y el resultado de la marcacion

def busquedaMarcarRectangulo(p,tamR,tamC,pizza,Rini,Cini,Rfin,Cfin,L,H):
    pizzaN = p
    slicesCMarcar = []

    actualC = Cini
    actualR = Rini
    while actualR < Rfin:
        destinoC = min(actualC + tamC - 1, Cfin - 1)
        destinoR = min(actualR + tamR - 1, Rfin - 1)
        if (disponible(pizzaN,actualC,actualR,destinoC,destinoR) and cortar(pizza,actualC, actualR, destinoC, destinoR,H,L) > 0):
            slicesCMarcar.append([actualR, actualC, destinoR, destinoC])
            pizzaN = marcar(pizzaN, actualC, actualR, destinoC, destinoR)
            actualC = destinoC + 1
        else:
            actualC = actualC + 1

        if actualC >= Cfin - 1:
            actualC = Cini
            actualR = actualR + 1

    return pizzaN, slicesCMarcar


# Buscamos rectangulos de tam t
def busquedaRectangulo(p,t,pizza,Rini,Cini,Rfin,Cfin,L,H):
    pizzaN=p
    if(t<4):
        return pizzaN,[]
    t = str(t)

    slices=[]

    for cuad in diccionarioCuadrados[t]:
    #    sys.stderr.write(str(cuad)+"\n")
        pizzaN,s=busquedaMarcarRectangulo(p,cuad[0],cuad[1],pizza,Rini,Cini,Rfin,Cfin,L,H)
        slices=list(merge(slices,s))

    return pizzaN,slices


# Buscamos cuadrados de tam t pero solo del mayor
def busquedaRectanguloMayor(p,t,pizza,Rini,Cini,Rfin,Cfin,L,H):
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

    #sys.stderr.write(str(mayorCuad)+"\n")
    pizzaN,s=busquedaMarcarRectangulo(p,mayorCuad[0],mayorCuad[1],pizza,Rini,Cini,Rfin,Cfin,L,H)
    slices=list(merge(slices,s))

    return pizzaN,slices



#calculamos el valor de cada pizza
def fitnessPizza(misSlices):
    tam=0
    if not misSlices:
        return 0

    for entrada in misSlices:
        if not entrada:
            continue
        tamTmp=(entrada[2]-entrada[0]+1)*(entrada[3]-entrada[1]+1)
        tam=tam+tamTmp

    return tam

def aplicarAlgoritmos(pizza,Rini,Cini,Rfin,Cfin,L,H):
    soluciones=[]


    # Buscamos la pista marcando HV
    p = np.zeros((Rfin, Cfin))
    p, slicesHorizontalMarcar = busquedaHorizontalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)
    p, slicesVerticalMarcar = busquedaVerticalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)

    slicesMarcarHV = list(merge(slicesHorizontalMarcar, slicesVerticalMarcar))

    soluciones.append(slicesMarcarHV)

    # Buscamos la pista marcando VH
    p = np.zeros((Rfin, Cfin))

    p, slicesVerticalMarcar = busquedaVerticalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)
    p, slicesHorizontalMarcar = busquedaHorizontalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)

    slicesMarcarVH = list(merge(slicesHorizontalMarcar, slicesVerticalMarcar))

    soluciones.append(slicesMarcarVH)

    # Buscamos la pista marcando cuadrados segun lista
    p = np.zeros((Rfin, Cfin))
    slicesResultCuadrados = []
    slicesResultCuadradosFinal = []
    for i in range(H, 3, -1):
        p, slicesCuadrados = busquedaRectangulo(p, i,pizza,Rini,Cini,Rfin,Cfin,L,H)
        slicesResultCuadrados = list(merge(slicesResultCuadrados, slicesCuadrados))
        #mensaje = "Row " + str(Rfin) + " col " + str(Cfin) + " probando cuadrado " + str(i) + "\n"
        #sys.stderr.write(mensaje)

    p2 = deepcopy(p)

    p, sTempH1 = busquedaHorizontalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)
    p, sTempV1 = busquedaVerticalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)
    sTemp1 = list(merge(sTempV1, sTempH1))
    sTemp1 = list(merge(sTemp1, slicesResultCuadrados))

    p2, sTempV2 = busquedaVerticalMarcar(p2,pizza,Rini,Cini,Rfin,Cfin,L,H)
    p2, sTempH2 = busquedaHorizontalMarcar(p2,pizza,Rini,Cini,Rfin,Cfin,L,H)
    sTemp2 = list(merge(sTempV2, sTempH2))
    sTemp2 = list(merge(sTemp2, slicesResultCuadrados))

    #mensaje = "S1 " + str(fitnessPizza(sTemp1)) + " S2 " + str(fitnessPizza(sTemp2)) + "\n"
    #sys.stderr.write(mensaje)

    if (fitnessPizza(sTemp1) > fitnessPizza(sTemp2)):
        slicesResultCuadradosFinal = sTemp1
    else:
        slicesResultCuadradosFinal = sTemp2

    soluciones.append(slicesResultCuadradosFinal)

    # Como el de antes, pero en lugar de todos cuadrados solo el mayor

    p = np.zeros((Rfin, Cfin))
    slicesResultCuadradosMayor = []
    slicesResultCuadradosMayorFinal = []
    for i in range(H, 3, -1):
        p, slicesCuadradosMayor = busquedaRectanguloMayor(p, i,pizza,Rini,Cini,Rfin,Cfin,L,H)
        slicesResultCuadradosMayor = list(merge(slicesResultCuadradosMayor, slicesCuadradosMayor))
        #mensaje = "Row " + str(Rfin) + " col " + str(Cfin) + " probando cuadrado Mayor de " + str(i) + "\n"
        #sys.stderr.write(mensaje)
    p2 = deepcopy(p)

    p, sTempH1 = busquedaHorizontalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)
    p, sTempV1 = busquedaVerticalMarcar(p,pizza,Rini,Cini,Rfin,Cfin,L,H)
    sTemp1 = list(merge(sTempV1, sTempH1))
    sTemp1 = list(merge(sTemp1, slicesResultCuadradosMayor))

    p2, sTempV2 = busquedaVerticalMarcar(p2,pizza,Rini,Cini,Rfin,Cfin,L,H)
    p2, sTempH2 = busquedaHorizontalMarcar(p2,pizza,Rini,Cini,Rfin,Cfin,L,H)
    sTemp2 = list(merge(sTempV2, sTempH2))
    sTemp2 = list(merge(sTemp2, slicesResultCuadradosMayor))

    #mensaje = "S1 M " + str(fitnessPizza(sTemp1)) + " S2 M " + str(fitnessPizza(sTemp2)) + "\n"
    #sys.stderr.write(mensaje)

    if (fitnessPizza(sTemp1) > fitnessPizza(sTemp2)):
        slicesResultCuadradosMayorFinal = sTemp1
    else:
        slicesResultCuadradosMayorFinal = sTemp2

    soluciones.append(slicesResultCuadradosMayorFinal)

    # Obtener la mejor solucion de las buscadas
    maxFitness = 0
    solBest=[]
    for sol in soluciones:
        fit = fitnessPizza(sol)
        if (fit > maxFitness):
            maxFitness = fit
            solBest = sol

    return solBest

