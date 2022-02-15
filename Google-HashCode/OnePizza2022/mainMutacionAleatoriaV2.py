#!/usr/bin/python3
from os import remove
import sys
import math
import random

import numpy as np



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
    for x in range(len(s)):
        if(s[x]==1):
            conjuntoSol.add(listaTotal[x])
        
    cad=""
    for x in conjuntoSol:
        cad=cad + " " + x

    print(str(len(conjuntoSol))+cad)


#Imprimir solucion

def scoreSolucion(s):

    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta,noLeGustaOrdenado,ingredientesDisponibles ,listaTotal

    conjuntoSol=set()
    for x in range(len(s)):
        if(s[x]==1):
            conjuntoSol.add(listaTotal[x])
        
            
    score=0
    for x in range(nClientes):
        # print(conjuntoSol)
        # print(set(leGusta[x]))
        # print(set(noLeGusta[x]))
        if( len(conjuntoSol | set(leGusta[x]))==len(conjuntoSol) and len(conjuntoSol & set(noLeGusta[x]))==0):
            score=score+1

    return score



def obtenerSolucion():

    global listaTotal

    f = open("D/1778.out", "r")
    solucionBase=f.read().split(" ")[1:]
    genes=[]
    genesMejor=[]
    tamGenesMejor=0
    score=1778

    
    for x in listaTotal:
        if x in solucionBase:
            genes.append(1)
        else:
            genes.append(0)

    tamGenesMejor=sum(genes)
    genesMejor=genes[:]


    haCambiado=True
    while(haCambiado):
        genes=genesMejor[:]
        haCambiado=False
        for i in range(len(genes)):
            genesJugar=genes[:]
            if(genesJugar[i]==0):
                genesJugar[i]=1
            else:
                genesJugar[i]=0
            scoreTMP=scoreSolucion(genesJugar)

            sys.stderr.write("Score: "+str(scoreTMP)+ " "+str(score)+" "+str(tamGenesMejor)+"\n")
            if(scoreTMP>score or (scoreTMP==score and tamGenesMejor<sum(genesJugar))):
                score=scoreTMP
                tamGenesMejor=sum(genesJugar)
                haCambiado=True
                genesMejor=genesJugar[:]



        genes=genesMejor[:]
        for i in range(10):
            num=random.randint(0,len(genes)-1)
            if(genes[num]==0):
                genes[num]=1
            else:
                genes[num]=0
            scoreTMP=scoreSolucion(genes)
            sys.stderr.write("Score: "+str(scoreTMP)+ " "+str(score)+" "+str(tamGenesMejor)+"\n")

            if(scoreTMP>score or (scoreTMP==score and tamGenesMejor<sum(genes))):
                tamGenesMejor=sum(genes)

                score=scoreTMP
                haCambiado=True
                genesMejor=genes[:]
            if(genes[num]==0):
                genes[num]=1
            else:
                genes[num]=0


    return genesMejor


#Main
def main():
    # Numero de potenciales clientes y otras variables globales
    global nClientes, leGusta, noLeGusta, noLeGustaOrdenado,ingredientesDisponibles,profundidadIngredientesIni,profundidadIngredientesFin, maxNoGustaIngredientesIni,maxNoGustaIngredientesFin, listaTotal


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

