#!/usr/bin/python3
import sys
import math
import random
import os

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

def imprimirSolucionFichero(s,nombre):
    
    cad=str(len(s))

    for x in s:
        cad=cad + " " + x

    f = open(nombre, "w")
    f.write(cad)
    f.close()



def enlaceGrafoIncompatibilidad(posA,posB):
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



def buscoMejor(mejoresUsados):
    global grafoClientes
    mejor=-1
    valorMejor=100000

    for i in range(len(grafoClientes)):
        if i in mejoresUsados:
            continue
        valorTMP=sum(grafoClientes[i])
        if (valorTMP<valorMejor):
            valorMejor=valorTMP
            mejor=i

    return mejor

def obtenerSolucion():
    global grafoClientes,listaTotal,noLeGustaOrdenado,maxNoGustaIngredientesIni,maxNoGustaIngredientesFin,profundidadIngredientesIni,profundidadIngredientesFin

    mejorSol=set()
    score=0
    buscando=True
    mejoresUsados=[]
    while(True):
        mejor=buscoMejor(mejoresUsados)
        if(mejor==-1):
            break
        #print("Cojo mejor "+str(mejor))
        mejoresUsados.append(mejor)
        sol=mejorSol.copy()
        for x in leGusta[mejor]:
            sol.add(x)
        puntos=scoreSolucion(sol)
        if(puntos<score):
            continue
        else:

            for x in leGusta[mejor]:
                mejorSol.add(x)
            #print(sol)
            

            if(puntos>score):
                print(puntos)
                score=puntos
                if puntos>1400 and not(os.path.isfile("E/"+str(score)+".out")):
                    imprimirSolucionFichero(mejorSol,"E/"+str(score)+".out")


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
    grafoClientes = [ [0]*nClientes for i in range(nClientes)]
  

    for i in range(nClientes):
        for j in range(i+1,nClientes):
            if grafoClientes[i][j]==0 and enlaceGrafoIncompatibilidad(i,j):
                grafoClientes[i][j]=1
                grafoClientes[j][i]=1


 





    #Ingredientes a eliminar
    #Profundidad ingredientes
    sol=obtenerSolucion()

    print(sol)



    imprimirSolucion(sol)
    #Imprimimos score en stderr
    sys.stderr.write("Score: "+str(scoreSolucion(sol))+"\n")

# Codigo a ejecutar inicial
main()

