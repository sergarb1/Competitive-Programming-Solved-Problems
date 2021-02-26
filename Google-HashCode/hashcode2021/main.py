#!/usr/bin/python3
import sys
import math
import random


# Variables gloables
tiempo=0
intersecciones=0
calles=0
coches=0
bonus=0
listaCalles=[]
listaCaminoCoches=[]
dicCalles={}
dicCallesInverso={}



#Funcion donde leemos la entrada, en variables globales
def leerEntrada():
    # global para usar variables globales
    global tiempo, intersecciones, calles, coches, bonus, listaCalles, listaCaminoCoches, dicCalles, dicCallesInverso

    tiempo, intersecciones, calles, coches, bonus = map(int, input().split())

    listaCalles = []
    idCalles=0
    # Leemos las calles
    for i in range(calles):
        descripcionCalle=input().split()
        #Asiganamos numero a calle
        if descripcionCalle[2] not in dicCalles:
            dicCalles[descripcionCalle[2]]=idCalles
            #Diccionario inverso para imprimir resultado
            dicCallesInverso[idCalles]=descripcionCalle[2]
            idCalles=idCalles+1

        listaCalles.append([int(descripcionCalle[0]),int(descripcionCalle[1]),int(dicCalles[descripcionCalle[2]]),int(descripcionCalle[3])])

    
    # Leemos los caminos
    listaCaminoCoches=[]
    for i in range(coches):
        #Ignoramos primer numero, porque ya tenemos el dato en la lista (es cuantas calles es el camino)
        descripcionCamino=input().split()
        listaCaminoCoches.append(descripcionCamino[1:])




def preprocesarEntrada():

    # global para usar variables globales
    global tiempo, intersecciones, calles, coches, bonus, listaCalles, listaCaminoCoches, dicCalles, dicCallesInverso

    def ordenarCalles(elementoP):
        return elementoP[1]
    listaCalles.sort(key=ordenarCalles,reverse=False)

    def ordenarCoches(elementoP):
        return len(elementoP[0])
    listaCaminoCoches.sort(key=ordenarCoches,reverse=False)
    return



def calcularSolucion():

    # global para usar variables globales
    global tiempo, intersecciones, calles, coches, bonus, listaCalles, listaCaminoCoches, dicCalles, dicCallesInverso

    #Obtengo calles a las que dar tiempo
    dicCallesTiempo={}

    for i in range (len(listaCaminoCoches)):
        for x in listaCaminoCoches[i]:
            if dicCalles[x] not in dicCallesTiempo:
                dicCallesTiempo[dicCalles[x]]=1
            else:
                dicCallesTiempo[dicCalles[x]]=dicCallesTiempo[dicCalles[x]]+1

    #print(dicCallesTiempo)

    totalHistograma=0


    valores=[]
    for x in dicCallesTiempo:
        totalHistograma=totalHistograma+dicCallesTiempo[x]
        valores.append([x,dicCallesTiempo[x]])


    def ordenarValores(elementoP):
        return elementoP[1]
    valores.sort(key=ordenarValores,reverse=True)



    #print("Total histograma " + str(totalHistograma),file=sys.stderr)
    #print(valores,file=sys.stderr)
    #print(calcularPuntosSolucion(res),file=sys.stderr)

    res={}


    for i in range(len(listaCalles)):
        miCalle=listaCalles[i]



        if miCalle[2] not in dicCallesTiempo or dicCallesTiempo[miCalle[2]]<1: # or miCalle[3]>80:
            continue

        else:

            if not miCalle[1] in res:
                res[miCalle[1]] = []

            tiempo= min(dicCallesTiempo[miCalle[2]],1)
        res[miCalle[1]].append([dicCallesInverso[miCalle[2]],tiempo])
    return res
    

#Funcion que imprime la solucion
def imprimirsolucion(r):
    
    #Imprimimos numero de envios
    print(len(r))
    for clave in r:
        print(clave)
        listaInterImprimir=r[clave]
        print(len(listaInterImprimir))
        for x in listaInterImprimir:
            print(str(x[0])+" "+str(x[1]))


def main():


    # global para usar variables globales
    global nPizzas, nEq2, nEq3, nEq4 


    # Leemos la entrada
    leerEntrada()

    # Preprocesamos entrada en variables globales (ordenar, hash, etc.)
    preprocesarEntrada()

    #Aqui guardaremos el resultado
    res=calcularSolucion()

    #print(pizzas)
    #print(calcularPuntosSolucion(res),file=sys.stderr)
    imprimirsolucion(res)

# Codigo a ejecutar inicial
main()

