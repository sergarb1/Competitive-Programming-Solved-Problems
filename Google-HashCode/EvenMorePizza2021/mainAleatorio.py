#!/usr/bin/python3
import sys
import math
import random

# Variables gloables
nPizzas=0
nEq2=0
nEq3=0
nEq4=0
pizzas=[]

def obtenerScoreSolucionCompleta(res):
    score=0
    for x in res:
        entrega=[]
        ingredientesUsados = set()
        for i in range(x[0]):
            for ingrediente in pizzas[x[i+1]][0]:
                ingredientesUsados.add(ingrediente)
        score=score+ len(ingredientesUsados)**2

    return score
#Funcion que imprime la solucion
def imprimirsolucion(r):
    print("===IMPRIMO SOLUCION ==")
    #Imprimimos numero de envios
    print(len(r))
    for x in r:
        #Imprimimos cada envio
        cad=str(x[0])
        for elemento in x[1:]:
            cad=cad+" "+str(elemento)
        print(cad)
    print("===FIN IMPRIMO SOLUCION ==")

def leerSolucion(fichero):
    f = open(fichero, "r")
    tmp=f.readlines()[1:]
    r=[]
    for x in tmp:
        r.append(list(map(int,x.strip().split(" "))))
    return r

def puntuacionEntregasPizzas(conjuntoEntregas):
    res = 0
    cantidades = [0, 0, 0, 0, 0]

    global nEq2, nEq3, nEq4

    # Si hay mas entrega que pizzas, score 0
    if(len(conjuntoEntregas) > nPizzas):
        return 0

    for entrega in conjuntoEntregas:
        # Si alguna entrega es mayor de 4 o menor de 2, 0 puntos de score
        tamEntrega = len(entrega)
        if(tamEntrega < 2 or tamEntrega > 4):
            return 0

        cantidades[tamEntrega] = cantidades[tamEntrega]+1

        # Comprobamos si superamos el total de entregas
        if(tamEntrega == 2 and cantidades[tamEntrega] > nEq2):
            return 0
        if(tamEntrega == 3 and cantidades[tamEntrega] > nEq3):
            return 0
        if(tamEntrega == 4 and cantidades[tamEntrega] > nEq4):
            return 0
        # Si no se supera total de entregas, continuamos
        res = res+puntuacionPizzas(entrega[0])
    return res


# funcion que devuelve la puntuacion de una lista con un conjunto de pizzas
def puntuacionPizzas(conjuntoPizzas):
    # conjunto para comprobar si un ingrediente se ha usada
    ingredientesUsados = set()

    for pizza in conjuntoPizzas:
        for ingrediente in pizza[0]:
            ingredientesUsados.add(ingrediente)

    # devuelvo el cuadrado del numero de ingredientes
    nIngredientes = len(ingredientesUsados)
    return nIngredientes**2


def main():
    # Numero pizzas, equipos de 2, 3 y 4 miembros
    global nPizzas, nEq2, nEq3, nEq4 
    nPizzas, nEq2, nEq3, nEq4= map(int, input().split())
    global pizzas
    pizzas=[]
    # Leemos todas las pizzas. Las metemos en una lista cada una, ignorando el primer elemento
    for i in range(nPizzas):
        #El campo 0 es la pizza 1, es el orden para mantenerlo
        pizzas.append([input().split()[1:],i])
    #Aqui guardaremos el resultado
    res=leerSolucion(sys.argv[1])
    vueltas=int(sys.argv[2])


    scoreMax=obtenerScoreSolucionCompleta(res)
    #print("Score: "+str(scoreMax))
    #imprimirsolucion(res)# Codigo a ejecutar inicial

    #print( '\x1b[6;30;42m'+'Prueba')
    for _ in range(vueltas):
        score=0
        resNueva=res[:]

        posA=random.randint(0,len(resNueva)-1)
        posB=random.randint(0,len(resNueva)-1)
        if(posA==posB):
            continue
        pizzaA=random.randint(0,len(resNueva[posA])-2)
        pizzaB=random.randint(0,len(resNueva[posB])-2)

        pA=resNueva[posA][pizzaA+1]
        pB=resNueva[posB][pizzaB+1]
        resNueva[posA][pizzaA+1]=pB
        resNueva[posB][pizzaB+1]=pA
        
        score=0
        score=obtenerScoreSolucionCompleta(resNueva)

        if(score>scoreMax):
            scoreMax=score
            res=resNueva[:]

            print( "Score: "+str(scoreMax))
            imprimirsolucion(resNueva)

# Codigo a ejecutar inicial
main()

