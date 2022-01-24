#!/usr/bin/python3
import sys
import math
import random

import numpy as np
import pygad


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

#Imprimir solucion

def imprimirSolucion(s):

    global listaTotal
    cad=""
    conjuntoSol=set(listaTotal)
    for pos in range (len(s)):
        if s[pos]:
            if (noLeGustaOrdenado[pos]) in conjuntoSol:
                conjuntoSol.remove(noLeGustaOrdenado[pos])
    
    for x in conjuntoSol:
        cad=cad + " " + x

    print(str(len(conjuntoSol))+cad)




def scoreSolucion(s,s_idx):

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

    return score

def obtenerSolucion():
    global listaTotal,noLeGustaOrdenado,maxNoGustaIngredientesIni,maxNoGustaIngredientesFin,profundidadIngredientesIni,profundidadIngredientesFin
    
    mejorSol=[]
    ga_instance = pygad.GA( gene_type=int,
                          init_range_low=0,
                       init_range_high=2,
                        num_generations=1000,
                       num_parents_mating=2,
                       fitness_func=scoreSolucion,
                       sol_per_pop=8,
                       num_genes=len(noLeGustaOrdenado),
                       #initial_population=[1]*(len(listaTotal)),
                       mutation_percent_genes=0.01,
                       mutation_type="random",
                       mutation_num_genes=3,
                       mutation_by_replacement=True,
                       random_mutation_min_val=0.0,
                       random_mutation_max_val=1.0)

    ga_instance.run()

    solution, solution_fitness, solution_idx = ga_instance.best_solution()
    print("Parameters of the best solution : {solution}".format(solution=solution))
    print("Fitness value of the best solution = {solution_fitness}".format(solution_fitness=solution_fitness))

    print(solution)
    mejorSol=solution
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
    sys.stderr.write("Score: "+str(scoreSolucion(sol,None))+"\n")

# Codigo a ejecutar inicial
main()

