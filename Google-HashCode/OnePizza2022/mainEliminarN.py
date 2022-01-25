#!/usr/bin/python3
import sys
import math
import random

import itertools as it

#NOTA PARA ACORDARME: QUITAR N INGREDIENTES USANDO PYTHON Y NO CON CODIGO COMO YO



#Variables globales
nClientes=0
leGusta=[]
noLeGusta=[]
noLeGustaOrdenado=[]
ingredientesDisponibles=set()
listaTotal=[]
profundidadIngredientesIni=0
profundidadIngredientesFin=0
maxNoGustaIngredientesIni=0
maxNoGustaIngredientesFin=0

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



def obtenerSolucion():
    global listaTotal,noLeGustaOrdenado,maxNoGustaIngredientesIni,maxNoGustaIngredientesFin,profundidadIngredientesIni,profundidadIngredientesFin

    
    mejorSol=listaTotal[:]
    
    for x in noLeGustaOrdenado:
        if x in mejorSol:
            mejorSol.remove(x)


    return mejorSol


#Main
def main():
    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta, noLeGustaOrdenado,ingredientesDisponibles,profundidadIngredientesIni,profundidadIngredientesFin, maxNoGustaIngredientesIni,maxNoGustaIngredientesFin, listaTotal


    #Indico que voy a coger el primer parametro como fichero de entrada
    fichero=sys.argv[1]
    myfile=open(fichero, "r")
    #De ese fichero, leemos no gusta ordenado
    for line in myfile:
        noLeGustaOrdenado.append(line.strip())

    #Obtenemos la profundidad de busqueda inicia deseada del segundo parametro
    eliminarIni=int(sys.argv[2])



    #Obtenemos la profundidad de busqueda final deseada del tercer parametro
    eliminarFin=int(sys.argv[3])

    noLeGustaOrdenado=noLeGustaOrdenado[eliminarIni:eliminarFin]
    


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
    sol=obtenerSolucion()




    imprimirSolucion(sol)
    #Imprimimos score en stderr
    sys.stderr.write("Score: "+str(scoreSolucion(sol))+"\n")

# Codigo a ejecutar inicial
main()

