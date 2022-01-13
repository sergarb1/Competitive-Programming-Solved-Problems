#!/usr/bin/python3
import sys
import math
import random


#Variables globales
nClientes=0
leGusta=[]
noLeGusta=[]
ingredientesDisponibles=set()


#Imprimir solucion

def imprimirSolucion(s):
    cad=str(len(s))

    for x in s:
        cad=cad + " " + x

    print(cad)

#Main
def main():
    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta,ingredientesDisponibles

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
    eliminar=["xdozp","qzfyo","sunhp","byyii"]#"akuof"]

    sol=[]
    for x in listaTotal:
        if x in eliminar:
            continue
        sol.append(x)

    imprimirSolucion(sol)


# Codigo a ejecutar inicial
main()

