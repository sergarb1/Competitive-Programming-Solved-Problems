#!/usr/bin/python3
from operator import le
import sys
import random
import pandas as pd


#Variables globales
nClientes=0
leGusta=[]
noLeGusta=[]
ingredientesNoGusta=set()
ingredientesDisponibles=set()


#Indico que voy a coger el primer parametro como fichero de entrada
fichero=sys.argv[1]
limiteINI=int(sys.argv[2])
limiteFIN=int(sys.argv[3])
sys.stdin = open(fichero, "r")



#Leo el numero de potenciales clientes 
nClientes=int(sys.stdin.readline())


#Por cada cliente, leemos sus preferencias que gustan y no gustan
j=0
for i in range(nClientes):
    leGusta.append(sys.stdin.readline().strip().split(" ")[1:])

    fila=sys.stdin.readline().strip().split(" ")[1:]
    if(len(fila)>=limiteINI and len(fila)<=limiteFIN and len(fila)>0):
        j=j+1
        noLeGusta.append(fila)
        for x in fila:
            ingredientesNoGusta.add(x)

    #Incluimos ingredientes que gustan a la lista total de ingredientes
    for ingr in leGusta[i]:
        ingredientesDisponibles.add(ingr)
    #Incluimos ingredientes que no gustan a la lista total de ingredientes
  
    if j>0:
        for ingr in noLeGusta[j-1]:
            ingredientesDisponibles.add(ingr)
    


#Dataframe de lo que gusta y no gusta:
dfGusta = pd.DataFrame(columns = ['Ingredientes', 'Conteo','Ratio'])
#Dataframe de lo que no gusta:
dfNoGusta = pd.DataFrame(columns = ['Ingredientes', 'Conteo','Ratio'])


for ingr in ingredientesNoGusta:
    #Para cada elemento, contamos cuantos hay

    elementosGus=sum(x.count(ingr) for x in leGusta)
    elementosNoG=sum(x.count(ingr) for x in noLeGusta)
    
    ratioGustaNoGusta=elementosGus/elementosNoG

    fila = pd.Series([ingr,elementosGus,ratioGustaNoGusta], index = dfGusta.columns)
    
    #Deprecated 
    # dfGusta = dfGusta.append(fila, ignore_index=True)
    #Lo cambio por pasar la serie a dataframe +  transponerla
    dfNoGusta=pd.concat([dfNoGusta,fila.to_frame().T])

dfNoGusta=dfNoGusta.sort_values('Ratio', ascending=True)



listaGusta=list(dfGusta["Ingredientes"])

#Imprimimos salida estandard los que no gustan
for x in dfNoGusta["Ingredientes"]:
    #if x in listaGusta:
    print(x)


#print(dfNoGusta.head(10))
