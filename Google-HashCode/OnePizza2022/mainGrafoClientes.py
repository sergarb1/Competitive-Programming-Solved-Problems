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
grafoClientes=[[]]

#Imprimir solucion

def imprimirSolucion(s):
    cad=str(len(s))

    for x in s:
        cad=cad + " " + x

    print(cad)


def eliminarEnlaceGrafo(posA,posB):
    global nClientes, leGusta, noLeGusta,noLeGustaOrdenado,ingredientesDisponibles ,listaTotal


    #Busco si tiene no le gusta. Si lo tiene, me cargo el enlace
    for x in leGusta[posA]:
        if x in noLeGusta[posB]:
            return True
    for x in leGusta[posB]:
        if x in noLeGusta[posA]:
            return True

    #Si no encuentro, mantengo el enlace
    return False



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
    global grafoClientes,listaTotal,noLeGustaOrdenado,maxNoGustaIngredientesIni,maxNoGustaIngredientesFin,profundidadIngredientesIni,profundidadIngredientesFin

    conjuntoSol=set()

    mejorLinea=0
    mejorSuma=0
    mejorSol=set()

    """ for i in range(len(grafoClientes)):
        mejorTMP=sum(grafoClientes[i])
        if mejorSuma<mejorTMP:
            mejorSuma=mejorTMP
            mejorLinea=i
    

    for i in range(len(grafoClientes[mejorLinea])):

        if(grafoClientes[mejorLinea][i]==1):
            for x in leGusta[i]:
                conjuntoSol.add(x)   
    """
    

    for j in range(len(grafoClientes)):
        conjuntoSol=set()
        for i in range(len(grafoClientes[j])):

            if(grafoClientes[j][i]==1):
                for x in leGusta[i]:
                    conjuntoSol.add(x)   
        puntos=scoreSolucion(conjuntoSol)
        if(puntos>mejorSuma):
            mejorSuma=puntos
            mejorSol=conjuntoSol
        sys.stderr.write("Score: "+str(puntos)+" "+str(j)+"\n")

    return mejorSol


#Main
def main():
    # Numero de potenciales clientes y otras variables globales
    global grafoClientes, nClientes, leGusta, noLeGusta, noLeGustaOrdenado,ingredientesDisponibles,profundidadIngredientesIni,profundidadIngredientesFin, maxNoGustaIngredientesIni,maxNoGustaIngredientesFin, listaTotal




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

    #Inicializamos todos los clientes conectados entre si
    grafoClientes = [ [1]*nClientes for i in range(nClientes)]
  

    for i in range(nClientes):
        for j in range(i+1,nClientes):
            if eliminarEnlaceGrafo(i,j):
                grafoClientes[i][j]=0


    #print(grafoClientes)





    #Ingredientes a eliminar
    #Profundidad ingredientes
    sol=obtenerSolucion()

    print(sol)



    imprimirSolucion(sol)
    #Imprimimos score en stderr
    sys.stderr.write("Score: "+str(scoreSolucion(sol))+"\n")

# Codigo a ejecutar inicial
main()

