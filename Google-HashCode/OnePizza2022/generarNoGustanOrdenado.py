#!/usr/bin/python3
import sys
import random
import pandas as pd


#Variables globales
nClientes=0
leGusta=[]
noLeGusta=[]
ingredientesDisponibles=set()


#Indico que voy a coger el primer parametro como fichero de entrada
fichero=sys.argv[1]
sys.stdin = open(fichero, "r")



#Leo el numero de potenciales clientes 
nClientes=int(sys.stdin.readline())


#Por cada cliente, leemos sus preferencias que gustan y no gustan
for i in range(nClientes):
    leGusta.append(sys.stdin.readline().strip().split(" ")[1:])
    noLeGusta.append(sys.stdin.readline().strip().split(" ")[1:])

    #Incluimos ingredientes que gustan a la lista total de ingredientes
    for ingr in leGusta[i]:
        ingredientesDisponibles.add(ingr)
    #Incluimos ingredientes que no gustan a la lista total de ingredientes
    for ingr in noLeGusta[i]:
        ingredientesDisponibles.add(ingr)
    


#Dataframe de lo que gusta y no gusta:
dfGusta = pd.DataFrame(columns = ['Ingredientes', 'Conteo'])
#Dataframe de lo que no gusta:
dfNoGusta = pd.DataFrame(columns = ['Ingredientes', 'Conteo'])

for ingr in ingredientesDisponibles:
    #Para cada elemento, contamos cuantos hay
    elementos=sum(x.count(ingr) for x in leGusta)

    fila = pd.Series([ingr,elementos], index = dfGusta.columns)
    dfGusta = dfGusta.append(fila, ignore_index=True)
    

for ingr in ingredientesDisponibles:
    #Para cada elemento, contamos cuantos hay
    elementos=sum(x.count(ingr) for x in noLeGusta)

    fila = pd.Series([ingr,elementos], index = dfNoGusta.columns)
    dfNoGusta = dfNoGusta.append(fila, ignore_index=True)

dfGusta=dfGusta.sort_values('Conteo', ascending=False)
pd.set_option("max_rows", None)
#dfGusta.head()

dfNoGusta=dfNoGusta.sort_values('Conteo', ascending=False)

#Imprimimos salida estandard los que no gustan
for x in dfNoGusta["Ingredientes"]:
    print(x)
