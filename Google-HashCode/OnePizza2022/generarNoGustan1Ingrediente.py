#!/usr/bin/python3
import sys
import random
import pandas as pd


#Variables globales
nClientes=0
leGusta=set()
noLeGusta=set()
ingredientesDisponibles=set()


#Indico que voy a coger el primer parametro como fichero de entrada
fichero=sys.argv[1]
sys.stdin = open(fichero, "r")

limiteINI=int(sys.argv[2])
limiteFIN=int(sys.argv[3])


#Leo el numero de potenciales clientes 
nClientes=int(sys.stdin.readline())


#Por cada cliente, leemos sus preferencias que gustan y no gustan
for i in range(nClientes):

    lineaGusta=sys.stdin.readline().strip().split(" ")[1:]
    for x in lineaGusta:
        leGusta.add(x)
    lineaNoGusta=sys.stdin.readline().strip().split(" ")[1:]
    if (len(lineaNoGusta)>=limiteINI and len(lineaNoGusta)<=limiteFIN):
        for x in lineaNoGusta:
            noLeGusta.add(x)





#Imprimimos salida estandard los que no gustan
for x in noLeGusta:
    if x in leGusta:
        print(x)
