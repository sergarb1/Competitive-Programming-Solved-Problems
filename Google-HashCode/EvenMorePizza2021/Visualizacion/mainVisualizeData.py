#!/usr/bin/python3
import sys
import math
import matplotlib.pyplot as plt
import numpy as np  
import random

# Variables gloables
nPizzas=0
nEq2=0
nEq3=0
nEq4=0


def diferencias(pA,pB):
   
    miUnion=set(pA[0])  | set(pB[0])

    return len(miUnion)

def main():
    # Numero pizzas, equipos de 2, 3 y 4 miembros
    global nPizzas, nEq2, nEq3, nEq4 
    
    #Leemos ficheros
    with open(sys.argv[1]) as f:
        content = f.readlines()

    #Leemos primera linea
    nPizzas, nEq2, nEq3, nEq4= map(int, content[0].split())
    pizzas = []
    diccionarioIngredientes={}




    minimoIngredientes=1000000000000
    maximoIngredientes=0

    # Leemos todas las pizzas. Las metemos en una lista cada una, ignorando el primer elemento
    for i in range(nPizzas):
        #El campo 0 es la pizza 1, es el orden para mantenerlo
        pizzas.append([content[i+1].split()[1:],i])
        for x in pizzas[i][0]:
            if(x in diccionarioIngredientes):
                diccionarioIngredientes[x]+=1
            else:
                diccionarioIngredientes[x]=1
        #Maximo y minimo ingredientes
        if(len(pizzas[i][0])>maximoIngredientes):
            maximoIngredientes=len(pizzas[i][0])

        if(len(pizzas[i][0])<minimoIngredientes):
            minimoIngredientes=len(pizzas[i][0])

    ingredientePorCadaPizza=list(len(x[0]) for x in pizzas)


    print("===Pizzas===")
    print("Total pizzas: "+str(nPizzas))
    print("Maximo ingredientes Pizza: "+str(maximoIngredientes))
    print("Minimo ingredientes Pizza: "+str(minimoIngredientes))
    print("Total de ingredientes diferentes: "+str(len(diccionarioIngredientes)))
    print("Media de ingredientes por Pizza: "+str(np.mean(ingredientePorCadaPizza)))
    print("-> Desviacion tipica: "+ str(np.std(ingredientePorCadaPizza)))
    print("-> Percentil 25: "+ str(np.percentile(ingredientePorCadaPizza, 25)))
    print("-> Percentil 50 (Mediana): "+ str(np.percentile(ingredientePorCadaPizza, 50)))
    print("-> Percentil 75: "+ str(np.percentile(ingredientePorCadaPizza, 75)))


    #Muestro de pizzas y calcular algoritmo Miguel para grupos
    listaMuestreo=random.sample(pizzas,500)

    totalSuma=0
    for pizzaA in listaMuestreo:
        valorPizza=0
        for pizzaB in listaMuestreo:
            valorPizza=diferencias(pizzaA,pizzaB)
            totalSuma=totalSuma+valorPizza

    #Dividimos numero de pizzas
    totalSuma=totalSuma/500

    print("Algoritmo Miguel "+str(totalSuma))
    exit()

    #Obtenemos ingredientes ordenados por cuanto aparecen
    listaIngredientesOrdenados=[(k, int(diccionarioIngredientes[k])) for k in sorted(diccionarioIngredientes, key=diccionarioIngredientes.get, reverse=True)]
    listaIngredientesOrdenadosSoloNumeros=[(k[1]) for k in listaIngredientesOrdenados]

    #Calculamos, cuanto de comunes son ingredientes a las pizzas
    print("\n\n===Ingredientes===")
    print("Numero de pizzas con ingrediente mas comun: "+str(max(listaIngredientesOrdenadosSoloNumeros)))
    print("Numero de pizzas con ingrediente menos comun: "+str(min(listaIngredientesOrdenadosSoloNumeros)))
    print("Media de veces que ingredientes aparecen en pizzas: "+str(np.mean(listaIngredientesOrdenadosSoloNumeros)))
    print("-> Desviacion tipica: "+ str(np.std(listaIngredientesOrdenadosSoloNumeros)))
    print("-> Percentil 25: "+ str(np.percentile(listaIngredientesOrdenadosSoloNumeros, 25)))
    print("-> Percentil 50 (Mediana): "+ str(np.percentile(listaIngredientesOrdenadosSoloNumeros, 50)))
    print("-> Percentil 75: "+ str(np.percentile(listaIngredientesOrdenadosSoloNumeros, 75)))

    #Imprimo histograma de cuantas v
    plt.title("'"+sys.argv[1]+"' - Histograma aparición ingredientes en pizzas")
    plt.style.use('ggplot')
    plt.xlabel("Frecuencia ingrediente")
    plt.ylabel("Ingredientes con misma frecuencia")
    plt.hist(listaIngredientesOrdenadosSoloNumeros)
    
    plt.savefig(sys.argv[1]+"-histograma.png")

    #Borramos lienzo
    plt.clf()

    #Dibujamos diagrama circular
    plt.title("'"+sys.argv[1]+"' - Circular aparición ingredientes en pizzas")
    plt.pie(listaIngredientesOrdenadosSoloNumeros,autopct="%1.1f%%")
    plt.savefig(sys.argv[1]+"-circulo.png")


# Codigo a ejecutar inicial
main()

