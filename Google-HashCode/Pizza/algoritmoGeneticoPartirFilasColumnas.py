#!/usr/bin/python3
import random
import json
import sys
import os

import AuxiliaresAlgoritmoGeneticosPartirFilasColumnas as aux

from heapq import merge

# Diccionario para evitar recalcular cosas calculadas
dicYaSolucionados={}

num = 5  # La cantidad de individuos que habra en la poblacion
pressure = 3  # Cuantos individuos se seleccionan para reproduccion. Necesariamente mayor que 2
mutation_chance = 0.2  # La probabilidad de que un individuo mute
tamCortes=0
iteracionesEvolucion=10
fitnessAntiguo=0
nombreMaximoAntiguo=""

#HAY QUE USAR GLOBAL PARA MODIFICAR VARIABLES GLOBALES!!!!


def individual(min, max):
    """
        Crea un individual
    """
    if min>=max:
        max=min+1
    rRows = random.randint(min, max)
    rCols = random.randint(min, max)

    listaR=[]
    listaC=[]
    tmp=0

    while(tmp<rRows):
        x=random.randint(0,R-1)
        if x not in listaR:
            listaR.append(x)
            tmp=tmp+1

    tmp = 0
    while (tmp < rCols):
        x = random.randint(0, C - 1)
        if x not in listaC:
            listaC.append(x)
            tmp = tmp + 1
    res=[]
    #anyadimos las listas ordenadas
    listaR=aux.eliminarDuplicadosLista(listaR)
    listaC=aux.eliminarDuplicadosLista(listaC)
    listaR.sort()
    listaC.sort()
    res.append(listaR)
    res.append(listaC)
    return res


def crearPoblacion():

    return [individual(1,tamCortes) for i in range(num)]

def calcularFitness(individuo):
    """
        Calcula el fitness de un individuo concreto.
    """
    global dicYaSolucionados

    tam = 0

    slices=[]
    slicesTMP=[]
    #Filas de cortes
    iAnt=0
    jAnt=0

    #Bucle doble 1

    for i in individuo[0]:
        for j in individuo[1]:
            if str([iAnt,jAnt,i,j]) in dicYaSolucionados:
                slicesTMP=dicYaSolucionados[str([iAnt,jAnt,i,j])]
                #sys.stderr.write("Ahorro")
            else:
                slicesTMP=aux.aplicarAlgoritmos(pizza,iAnt,jAnt,i,j,L,H)
                dicYaSolucionados[str([iAnt,jAnt,i,j])]=slicesTMP
            slices=list(merge(slicesTMP,slices))
            jAnt=j
        if jAnt<C:

            if str([iAnt,jAnt,i,C]) in dicYaSolucionados:
                slicesTMP=dicYaSolucionados[str([iAnt,jAnt,i,C])]
                #sys.stderr.write("Ahorro")
            else:
                slicesTMP=aux.aplicarAlgoritmos(pizza,iAnt,jAnt,i,C,L,H)
                dicYaSolucionados[str([iAnt,jAnt,i,C])]=slicesTMP
            slices=list(merge(slicesTMP,slices))


        jAnt=0
        iAnt=i
    # Bucle 2
    if iAnt<R:
        for j in individuo[1]:

            if str([iAnt, jAnt, R, j]) in dicYaSolucionados:
                slicesTMP=dicYaSolucionados[str([iAnt, jAnt, R, j])]
                #sys.stderr.write("Ahorro")
            else:
                slicesTMP = aux.aplicarAlgoritmos(pizza, iAnt, jAnt, R, j, L, H)
                dicYaSolucionados[str([iAnt, jAnt, R, j])]=slicesTMP
            slices = list(merge(slicesTMP, slices))
            jAnt = j
    if iAnt<R and jAnt<C:
        if str([iAnt,jAnt,R,C]) in dicYaSolucionados:
            #sys.stderr.write("Ahorro")
            slicesTMP=dicYaSolucionados[str([iAnt,jAnt,R,C])]
        else:
            slicesTMP = aux.aplicarAlgoritmos(pizza, iAnt, jAnt, R, C, L, H)
            dicYaSolucionados[str([iAnt, jAnt, R, C])]=slicesTMP
        slices = list(merge(slicesTMP, slices))

    tam=aux.fitnessPizza(slices)

    return tam,slices


def selection_and_reproduction(population):
    global fitnessAntiguo
    """
        Puntua todos los elementos de la poblacion (population) y se queda con los mejores
        guardandolos dentro de 'selected'.
        Despues mezcla el material genetico de los elegidos para crear nuevos individuos y
        llenar la poblacion (guardando tambien una copia de los individuos seleccionados sin
        modificar).

        Por ultimo muta a los individuos.

    """
    puntuados=[]

    for i in population:
        res,slices=calcularFitness(i)
        puntuados.append([res,i])
        if res>fitnessAntiguo:
            aux.actualizarMaximoAntiguo(nombreMaximoAntiguo,slices)
            fitnessAntiguo=res
            sys.stderr.write("Nuevo de tam "+str(res)+" "+str(slices))


    puntuados = [(calcularFitness(i), i) for i in
                 population]  # Calcula el fitness de cada individuo, y lo guarda en pares ordenados de la forma (5 , [1,2,1,1,4,1,8,9,4,1])
    puntuados = [i[1] for i in sorted(puntuados)]  # Ordena los pares ordenados y se queda solo con el array de valores
    population = puntuados

    selected = puntuados[(len(
        puntuados) - pressure):]  # Esta linea selecciona los 'n' individuos del final, donde n viene dado por 'pressure'

    # Se mezcla el material genetico para crear nuevos individuos
    for i in range(len(population) - pressure):



        padre = random.sample(selected, 2)  # Se eligen dos padres

        largoR0=len(padre[0][0])
        largoC0=len(padre[0][1])
        largoR1=len(padre[1][0])
        largoC1=len(padre[1][1])


        puntoR0 = random.randint(0, max(largoR0 - 1,1))  # Se elige un punto para hacer el intercamio
        puntoC0 = random.randint(0, max(largoC0 - 1,1))  # Se elige un punto para hacer el intercambio
        puntoR1 = random.randint(0, max(largoR1 - 1,1))  # Se elige un punto para hacer el intercambio
        puntoC1 = random.randint(0, max(largoC1 - 1,1))  # Se elige un punto para hacer el intercambio


        population[i][0] = padre[0][0][:puntoR0]  # Se mezcla el material genetico de los padres en cada nuevo individuo
        population[i][0]=list(merge(population[i][0],padre[1][0][puntoR1:]))
        population[i][1] = padre[0][1][:puntoC0]  # Se mezcla el material genetico de los padres en cada nuevo individuo
        population[i][1]=list(merge(population[i][1],padre[1][1][puntoC1:]))

        #Eliminamos duplicados
        #print("Individuo row "+str(i)+" antes "+str(population[i][0]))

        population[i][0] = aux.eliminarDuplicadosLista(population[i][0])
        #print("Individuo row "+str(i)+" despues "+str(population[i][0]))
        #print("Individuo col " + str(i) + " antes "+ str(population[i][1]))

        population[i][1] = aux.eliminarDuplicadosLista(population[i][1])
        #print("Individuo col " + str(i) + " despues "+ str(population[i][1]))
        population[i][0].sort()
        population[i][1].sort()
    return population  # El array 'population' tiene ahora una nueva poblacion de individuos, que se devuelven


def mutation(population):
    """
        Se mutan los individuos al azar. Sin la mutacion de nuevos genes nunca podria
        alcanzarse la solucion.
    """
    for i in range(len(population) - pressure):
        if random.random() <= mutation_chance:  # Cada individuo de la poblacion (menos los padres) tienen una probabilidad de mutar
            largoR0 = len(population[i][0])
            largoC0 = len(population[i][1])

            puntoR0=0
            puntoC0=0
            if largoR0-1>0:
                puntoR0 = random.randint(0, largoR0 - 1)  # Se elige un punto para hacer el intercambio

            if largoC0 - 1 > 0:
                puntoC0 = random.randint(0, largoC0 - 1)  # Se elige un punto para hacer el intercambio

            nuevo_valorR = random.randint(1, R - 1)  # y un nuevo valor para este punto

            #Si hay lista
            if population[i][0]:


                # Es importante mirar que el nuevo valor no sea igual al viejo
                while nuevo_valorR == population[i][0][puntoR0]:
                    nuevo_valorR = random.randint(1, R-1)
                # Se aplica la mutacion
                population[i][0][puntoR0] = nuevo_valorR

            else:
                population[i][0] = [nuevo_valorR]


            nuevo_valorC = random.randint(1, C - 1)  # y un nuevo valor para este punto
            #Si hay lista
            if population[i][1]:

                # Es importante mirar que el nuevo valor no sea igual al viejo


                while nuevo_valorC == population[i][1][puntoC0]:
                    nuevo_valorC = random.randint(1, C-1)

                population[i][1][puntoC0] = nuevo_valorC
            else:
                population[i][1] = [nuevo_valorC]

            # Eliminamos duplicados y ordenamos
            population[i][0] = aux.eliminarDuplicadosLista(population[i][0])
            population[i][1] = aux.eliminarDuplicadosLista(population[i][1])
            population[i][0].sort()
            population[i][1].sort()

    return population


def algoritmoGenetico():
    population=crearPoblacion()

    # Se evoluciona la poblacion
    for i in range(iteracionesEvolucion):
        #print("Iteracion "+str(i))
        #print("Normal")
        mensaje = "Iteracion " + str(i)+"\n"
        sys.stderr.write(mensaje)

        #print(population)

        population = selection_and_reproduction(population)
        #print("Procreada")
        #print(population)
        population = mutation(population)
        #print("Mutada")
        #print(population)




    return population






#main
def main():
    #Variables globales que necesitan ser escrita
    global R,C,L,H,pizza,tamCortes,dicYaSolucionados,fitnessAntiguo, nombreMaximoAntiguo

    nombreMaximoAntiguo=sys.argv[1]
    R,C,L,H=map(int, input().split())

    tamCortes = min(int(min(R,C)/2),200)
    pizza = []
    for _ in range(R):
        pizza.append(input())

    #Cargamos el precalculo de soluciones
    if os.path.isfile(nombreMaximoAntiguo+'Precalculos.json'):
        with open(nombreMaximoAntiguo+'Precalculos.json') as data_file:
            dicYaSolucionados = json.load(data_file)

    #Cargamos la solucion del mejor
    fitnessAntiguo=aux.calcularMaximoAntiguo(nombreMaximoAntiguo)


    #Hacemos el algoritmo genetico
    res=algoritmoGenetico()

    #Finalmente guardamos el precalculo
    with open(sys.argv[1]+'Precalculos.json', 'w') as outfile:
        json.dump(dicYaSolucionados, outfile)

if __name__ == "__main__":
    # execute only if run as a script
    main()
