#!/usr/bin/python3
import sys
import math
import random

#NOTA PARA ACORDARME: QUITAR N INGREDIENTES USANDO PYTHON Y NO CON CODIGO COMO YO



#Variables globales
nClientes=0
leGusta=[]
noLeGusta=[]
noLeGustaOrdenado=[]
ingredientesDisponibles=set()
listaTotal=[]

#Imprimir solucion

def imprimirSolucion(s):
    cad=str(len(s))

    for x in s:
        cad=cad + " " + x

    print(cad)


#Imprimir solucion

def scoreSolucion(s):

    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta,noLeGustaOrdenado,ingredientesDisponibles ,listaTotal

    conjuntoSol=set(s)
    score=0
    for x in range(nClientes):
        # print(conjuntoSol)
        # print(set(leGusta[x]))
        # print(set(noLeGusta[x]))
        if( len(conjuntoSol | set(leGusta[x]))==len(conjuntoSol) and len(conjuntoSol & set(noLeGusta[x]))==0):
            score=score+1

    return score





#Obtenemos solucion
def obtenerSolucion(listaTotal,indiceNoGusta,profundidad):
    global noLeGustaOrdenado

    listaTmp=[]

    mejorScore=0
    mejorSol=[]
    for a in listaTotal:
        if a!=noLeGustaOrdenado[indiceNoGusta]:
            listaTmp.append(a)
    
    if(profundidad<=0):
        return listaTmp
    
    z=indiceNoGusta+1
    while z < len(noLeGustaOrdenado):
        sol=obtenerSolucion(listaTmp,z,profundidad-1)
        puntos=scoreSolucion(sol)
        if(puntos>mejorScore):
            mejorScore=puntos
            mejorSol=sol

        z=z+1
    return mejorSol




#Main
def main():
    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta, noLeGustaOrdenado,ingredientesDisponibles


    #Indico que voy a coger el primer parametro como fichero de entrada
    fichero=sys.argv[1]
    myfile=open(fichero, "r")
    #De ese fichero, leemos no gusta ordenado
    for line in myfile:
        noLeGustaOrdenado.append(line)

    #Obtenemos la profundidad de busqueda deseada del segundo parametro
    profundidadIngredientes=int(sys.argv[2])

    


    #Leo el numero de potenciales clientes 
    nClientes=int(input())




    #Por cada cliente, leemos sus preferencias que gustan y no gustan
    for i in range(nClientes):
        leGusta.append(input().split(" ")[1:])
        noLeGusta.append(input().split(" ")[1:])

        #Incluimos ingredientes que gustan a la lista total de ingredientes
        for ingr in leGusta[i]:
            ingredientesDisponibles.add(ingr)

    #Solucion con todos los ingredientes
    listaTotal= list(ingredientesDisponibles)

    #Ingredientes a eliminar
    #Profundidad ingredientes
    sol=obtenerSolucion(listaTotal,0,profundidadIngredientes-1)




    imprimirSolucion(sol)
    print(scoreSolucion(sol))

# Codigo a ejecutar inicial
main()

