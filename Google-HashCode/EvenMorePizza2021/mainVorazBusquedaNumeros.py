#!/usr/bin/python3
import sys
import math

# Variables gloables
nPizzas=0
nEq2=0
nEq3=0
nEq4=0

def diferencias4(pA,pB,pC,pD):
    #Usamos union exclusiva, con ^. La union normal es | y la interseccion &
    #Usamos union exclusiva, con ^. La union normal es | y la interseccion &
    miUnion=set(pA[0])  ^  set(pB[0]) ^ set(pC[0]) ^  set(pD[0])

    return len(miUnion)

def diferencias3(pA,pB,pC):
   
    miUnion=set(pA[0])  ^  set(pB[0])  ^  set(pC[0]) 

    return len(miUnion)

def diferencias2(pA,pB):
   
    miUnion=set(pA[0])  ^  set(pB[0])

    return len(miUnion)


def mejorComb4(pizzas,limite):


    mejorDif=-1
    p0=pizzas[0]
    p1=pizzas[1]
    p2=pizzas[2]
    p3=pizzas[3]
    
    for i in range(min(limite,len(pizzas))):
        for j in range(i,min(limite,len(pizzas))):
            for k in range(j,min(limite,len(pizzas))):
                for l in range(k,min(limite,len(pizzas))):
                    if(i==j or i==k or i==l or j==k or j==l or k==l):
                        continue
                    dif4=diferencias4(pizzas[i],pizzas[j],pizzas[k],pizzas[l])

                    if(dif4>=mejorDif):
                        mejorDif=dif4
                        p0=pizzas[i]
                        p1=pizzas[j]
                        p2=pizzas[k]
                        p3=pizzas[l]

    return p0,p1,p2,p3


def mejorComb3(pizzas,limite):


    mejorDif=-1
    p0=pizzas[0]
    p1=pizzas[1]
    p2=pizzas[2]
    
    for i in range(min(limite,len(pizzas))):
        for j in range(i,min(limite,len(pizzas))):
            for k in range(j,min(limite,len(pizzas))):
                if(i==j or i==k or j==k):
                    continue
                dif3=diferencias3(pizzas[i],pizzas[j],pizzas[k])


                if(dif3>=mejorDif):
                    mejorDif=dif3
                    p0=pizzas[i]
                    p1=pizzas[j]
                    p2=pizzas[k]
    
    return p0,p1,p2


def mejorComb2(pizzas,limite):


    mejorDif=-1
    p0=pizzas[0]
    p1=pizzas[1]
    
    for i in range(min(limite,len(pizzas))):
        for j in range(i,min(limite,len(pizzas))):
                if(i==j):
                    continue
                dif2=diferencias2(pizzas[i],pizzas[j])


                if(dif2>=mejorDif):
                    mejorDif=dif2
                    p0=pizzas[i]
                    p1=pizzas[j]
    
    return p0,p1



#Funcion que imprime la solucion
def imprimirsolucion(r):
    
    #Imprimimos numero de envios
    print(len(r))
    for x in r:
        #Imprimimos cada envio
        cad=str(x[0])
        for elemento in x[1:]:
            cad=cad+" "+str(elemento)
        print(cad)


def main():

    #LO DE LOS NUMEROS Diccionario para lo de los numeros
    dicIngredientes={}
    idIngredientes=0

    # Numero pizzas, equipos de 2, 3 y 4 miembros
    global nPizzas, nEq2, nEq3, nEq4 
    nPizzas, nEq2, nEq3, nEq4= map(int, input().split())
    pizzas = []
    # Leemos todas las pizzas. Las metemos en una lista cada una, ignorando el primer elemento
    for i in range(nPizzas):

        #LO DE LOS NUMEROS leo los ingredientes
        ingredientes=input().split()[1:]
        ingredientesNum=[]

        for x in ingredientes:
            if x not in dicIngredientes:
                dicIngredientes[x]=idIngredientes
                idIngredientes=idIngredientes+1

            ingredientesNum.append(dicIngredientes[x])
         
        #El campo 0 es la pizza 1, es el orden para mantenerlo
        pizzas.append([ingredientesNum,i])
    #Aqui guardaremos el resultado
    res=[]
    #print(pizzas)
    #print(puntuacionPizzas([pizzas[1][0], pizzas[2][0]]))


    #Ordenamos pizzas por el numero de ingredientes
    def ordenarPizzasIngredientes(elementoP):
        return len(elementoP[0])
    pizzas.sort(key=ordenarPizzasIngredientes,reverse=True)



    #if(len(pizzas)%1000==0):
    #print(len(pizzas),file=sys.stderr)
 




    while(nEq4>0 and len(pizzas)>=4):
        if(len(pizzas)%2==0):
            print(len(pizzas),file=sys.stderr)
     
        #Le pasamos las N primeras a probar
        pizza0,pizza1,pizza2,pizza3=mejorComb4(pizzas, min(len(pizzas),40))
        
        
        res.append([4,pizza0[1],pizza1[1],pizza2[1],pizza3[1]])

        pizzas.remove(pizza0)
        pizzas.remove(pizza1)
        pizzas.remove(pizza2)
        pizzas.remove(pizza3)
        nEq4=nEq4-1



    while(nEq3>0 and len(pizzas)>=3):
        
        if(len(pizzas)%10==0):
            print(len(pizzas),file=sys.stderr)
 


        #Le pasamos las N primeras a probar
        pizza0,pizza1,pizza2=mejorComb3(pizzas, min(len(pizzas),40))

        res.append([3,pizza0[1],pizza1[1],pizza2[1]])

        pizzas.remove(pizza0)
        pizzas.remove(pizza1)
        pizzas.remove(pizza2)
        nEq3=nEq3-1

    while(nEq2>0 and len(pizzas)>=2):
        
        if(len(pizzas)%10==0):
            print(len(pizzas),file=sys.stderr)


        #Le pasamos las N primeras a probar
        pizza0,pizza1=mejorComb2(pizzas, min(len(pizzas),40))

        res.append([2,pizza0[1],pizza1[1]])

        pizzas.remove(pizza0)
        pizzas.remove(pizza1)
        nEq2=nEq2-1










    imprimirsolucion(res)

# Codigo a ejecutar inicial
main()

