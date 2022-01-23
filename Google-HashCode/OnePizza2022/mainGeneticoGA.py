#!/usr/bin/python3
from os import remove
import sys
import math
import random

import numpy as np
from geneticalgorithm import geneticalgorithm as ga



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

    global listaTotal
    conjuntoSol=set()
    print(listaTotal)
    print(s)
    for pos in range (len(listaTotal)):
        print(pos)
        if s[pos]:
            conjuntoSol.add(listaTotal[pos])
    cad=str(len(s))

    for x in conjuntoSol:
        cad=cad + " " + x

    print(cad)


#Imprimir solucion

def scoreSolucion(s):

    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta,noLeGustaOrdenado,ingredientesDisponibles ,listaTotal

    conjuntoSol=set(listaTotal)
    for pos in range (len(s)):
        if s[pos]:
            if (noLeGustaOrdenado[pos]) in conjuntoSol:
                conjuntoSol.remove(noLeGustaOrdenado[pos])
            
    score=0
    for x in range(nClientes):
        # print(conjuntoSol)
        # print(set(leGusta[x]))
        # print(set(noLeGusta[x]))
        if( len(conjuntoSol | set(leGusta[x]))==len(conjuntoSol) and len(conjuntoSol & set(noLeGusta[x]))==0):
            score=score+1

    return -score



def obtenerSolucion():
    global listaTotal,noLeGustaOrdenado,maxNoGustaIngredientesIni,maxNoGustaIngredientesFin,profundidadIngredientesIni,profundidadIngredientesFin
    algorithm_param = {'max_num_iteration': 1000,\
                   'population_size':100,\
                   'mutation_probability':0.1,\
                   'elit_ratio': 0.01,\
                   'crossover_probability': 0.5,\
                   'parents_portion': 0.3,\
                   'crossover_type':'uniform',\
                   'max_iteration_without_improv':None}

    model=ga(function=scoreSolucion,dimension=len(noLeGustaOrdenado),variable_type='bool',algorithm_parameters=algorithm_param)

    model.run()
    mejorSol=model.output_dict["variable"]
    print(mejorSol)
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

