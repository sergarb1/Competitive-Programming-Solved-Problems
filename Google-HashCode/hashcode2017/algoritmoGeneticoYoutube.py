#!/usr/bin/python3
import random
import json
import sys
import os

import AuxiliaresAlgoritmoGeneticosYoutube as aux

from heapq import merge
from random import shuffle

# Diccionario para evitar recalcular cosas calculadas
dicYaSolucionados={}

num = 3  # La cantidad de individuos que habra en la poblacion
pressure = 3  # Cuantos individuos se seleccionan para reproduccion. Necesariamente mayor que 2
mutation_chance = 0.2  # La probabilidad de que un individuo mute
tamCortes=0
iteracionesEvolucion=10
mejorFitness=0
mejorIndividuo=[]
nombreMaximoAntiguo=""
totalRequest=0

# FUNCIONES DEL PROBLEMA


def eliminarNoCaben(individuo):
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo

    shuffle(individuo)


    #Preparamos el resultado
    dicResultado={}
    for i in range(C):
        dicResultado[i]=[]

    for x in individuo:
        dicResultado[x[0]].append(x[1])



    #Elimino
    for n in range(C):
        if cuantoLibre(n,dicResultado)<0:
            for entrada in individuo:
                if entrada[0]==n:

                    individuo.remove(entrada)

                    ''' Rehacemos dicResultado'''

                    # Preparamos el resultado
                    dicResultado = {}
                    for i in range(C):
                        dicResultado[i] = []

                    for x in individuo:
                        dicResultado[x[0]].append(x[1])
                if cuantoLibre(n,dicResultado)>=0:
                    break

    return individuo

def cuantoLibre(numCache,dicResultado):
    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo

    if numCache not in dicResultado:
        return X

    lista=dicResultado[numCache]

    res=0
    for i in range(len(lista)):
        res=res+int(videos[lista[i]])


    return X-res


#HAY QUE USAR GLOBAL PARA MODIFICAR VARIABLES GLOBALES!!!!


def individual():
    """
        Crea un individual
    """

    global V, E, R, C, X, videos, dicEndCache, dicEndCentral, dicEndVideo, dicResultado

    mensaje = "Creando hijo\n"
    sys.stderr.write(mensaje)

    res=[]
    dicResultado={}
    #recorremos todas las caches
    for n in range(C):

        mensaje = "Cache "+str(n)+" Videos "+str(V)+"\n"
        sys.stderr.write(mensaje)
        # Videos en orden aleatorio
        listaVRandom=[]
        for i in range(V):
            listaVRandom.append(i)
        #Desordenamos la lista
        shuffle(listaVRandom)

        libre = cuantoLibre(n, dicResultado)
        for m in listaVRandom:
            if libre <0:
                break
            if [n,m] not in res and libre>=int(videos[m]):
                if n not in dicResultado:
                    dicResultado[n]=[]
                dicResultado[n].append(m);
                res.append([n,m])

                libre = cuantoLibre(n, dicResultado)

    res = aux.eliminarDuplicadosLista(res)

    return res


def crearPoblacion():

    return [individual() for i in range(num)]


#OJO no sale el mismo numero que en google, por temas de optimizacion
def calcularFitness(individuo):
    """
        Calcula el fitness de un individuo concreto.
    """
    global V,dicEndVideo,dicEndCentral,totalRequest

    res=0

    for endpoint in dicEndVideo:
        # latencia al central
        latCentral=dicEndCentral[endpoint][0]

        for video in dicEndVideo[endpoint]:
            mejor=latCentral
            for x in individuo:
                #Si es ese video
                if x[1]==video:
                    # Si esta esa cache conectada
                    if x[0] in dicEndCache[endpoint]:
                        if dicEndCache[endpoint][x[0]]<mejor:
                            mejor=dicEndCache[endpoint][x[0]]

            res+=dicEndVideo[endpoint][video]*(latCentral-mejor)
#            mensaje = "Latencia central " + str(latCentral) + " endpoint " + str(endpoint) + " video " + str(video) + " mejor " + str(mejor) + " res " + str(res) + "\n"
#            sys.stderr.write(mensaje)

    return res,(res)/totalRequest*1000



def selection_and_reproduction(population):
    global mejorFitness,mejorIndividuo
    """
        Puntua todos los elementos de la poblacion (population) y se queda con los mejores
        guardandolos dentro de 'selected'.
        Despues mezcla el material genetico de los elegidos para crear nuevos individuos y
        llenar la poblacion (guardando tambien una copia de los individuos seleccionados sin
        modificar).

        Por ultimo muta a los individuos.

    """
    puntuados=[]

    for i in range(len(population)):
        population[i]=eliminarNoCaben(population[i])
    for i in population:
        res,valorGoogle=calcularFitness(i)
        #Si encontramos al mejor, nos lo guardamos
        if res>mejorFitness:
            mejorFitness=res
            mejorIndividuo=i
            mensaje = "Mejor " + str(int(valorGoogle))+"\n"
            sys.stderr.write(mensaje)
            with open(nombreMaximoAntiguo+'mejor.json', 'w') as outfile:
                json.dump(mejorIndividuo, outfile)

        puntuados.append([res,i])


    puntuados = [(calcularFitness(i), i) for i in
                 population]  # Calcula el fitness de cada individuo, y lo guarda en pares ordenados de la forma (5 , [1,2,1,1,4,1,8,9,4,1])
    puntuados = [i[1] for i in sorted(puntuados)]  # Ordena los pares ordenados y se queda solo con el array de valores
    population = puntuados

    selected = puntuados[(len(
        puntuados) - pressure):]  # Esta linea selecciona los 'n' individuos del final, donde n viene dado por 'pressure'

    # Se mezcla el material genetico para crear nuevos individuos
    for i in range(len(population) - pressure):



        padre = random.sample(selected, 2)  # Se eligen dos padres

        shuffle(padre[0])
        shuffle(padre[1])

        largoR0=len(padre[0])
        largoR1=len(padre[1])


        puntoR0 = random.randint(0, max(largoR0 - 1,1))  # Se elige un punto para hacer el intercamio inicial
        puntoR1 = random.randint(0, max(largoR1 - 1,1))  # Se elige un punto para hacer el intercambio


        population[i] = padre[0][:puntoR0]  # Se mezcla el material genetico de los padres en cada nuevo individuo
        population[i]=list(merge(population[i],padre[1][puntoR1:]))

        #Eliminamos duplicados
        #print("Individuo row "+str(i)+" antes "+str(population[i][0]))
        population[i] = aux.eliminarDuplicadosLista(population[i])
        population[i] = eliminarNoCaben(population[i])

    return population  # El array 'population' tiene ahora una nueva poblacion de individuos, que se devuelven


def mutation(population):
    """
        Se mutan los individuos al azar. Sin la mutacion de nuevos genes nunca podria
        alcanzarse la solucion.
    """
    for i in range(len(population) - pressure):
        if random.random() <= mutation_chance:  # Cada individuo de la poblacion (menos los padres) tienen una probabilidad de mutar
            largoR0 = len(population[i])

            puntoR0=0
            if largoR0-1>0:
                puntoR0 = random.randint(0, largoR0 - 1)  # Se elige un punto para hacer el intercambio

            nuevo_valorR = random.choice(individual())  # y un nuevo valor para este punto

            #Si hay lista
            if population[i]:


                # Se aplica la mutacion
                population[i][puntoR0][0] = nuevo_valorR[0]
                population[i][puntoR0][1] = nuevo_valorR[1]

            else:
                population[i] = [[nuevo_valorR[0],nuevo_valorR[1]]]



            # Eliminamos duplicados y ordenamos
            population[i] = aux.eliminarDuplicadosLista(population[i])
            population[i] = eliminarNoCaben(population[i])


    return population


def algoritmoGenetico():

    global mejorIndividuo
    population=crearPoblacion()
    population.append(mejorIndividuo)


    #Cargamos el mejor del concurso
    if os.path.isfile(nombreMaximoAntiguo2 + '.json'):
        with open(nombreMaximoAntiguo2 + '.json') as data_file:
            mejorConcurso = json.load(data_file)

    population.append(mejorConcurso)

    r,tmp=calcularFitness(mejorConcurso)

    mensaje = "Mejor concurso " + str(tmp) + "\n"
    sys.stderr.write(mensaje)

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
    global V,E,R,C,X,videos,dicEndCache,dicEndCentral,dicEndVideo,dicResultado,mejorIndividuo,totalRequest,mejorFitness,nombreMaximoAntiguo,nombreMaximoAntiguo2



    nombreMaximoAntiguo=sys.argv[1]

    nombreMaximoAntiguo2=sys.argv[2]

    V, E, R, C, X=map(int, input().split())

    videos=(input().split())


    dicResultado={}
    #hola google

    #Aqui las latencias y la latencia del endpoint sevidor
    #Latencia de el endpoint con los servidores cache que tengan (pueden ser 0)
    dicEndCache={}
    #Latencia endpoint con servidor
    dicEndCentral=[]
    #Diccionario que guarda numero de peticiones desde un endpoint  de un video
    dicEndVideo={}


    for i in range(E):
        LCentral, Ncaches = map(int, input().split())
        dicEndCache[i]={}

        dicEndCentral.append([LCentral,i])
        for j in range(Ncaches):
            Ecache, Lcache = map(int, input().split())
            dicEndCache[i][Ecache]=Lcache

    #Ordenamos endpoints por orden mayor latencia



    #Request
    for i in range(R):
        Nvideo, Evideo, Nrequest = map(int, input().split())
        if Evideo in dicEndVideo:
            if Nvideo in dicEndVideo[Evideo]:
                dicEndVideo[Evideo][Nvideo] =dicEndVideo[Evideo][Nvideo]+ Nrequest
            else:
                dicEndVideo[Evideo][Nvideo]=Nrequest
        else:
            dicEndVideo[Evideo]={}
            dicEndVideo[Evideo][Nvideo] = Nrequest
        totalRequest=totalRequest+Nrequest


    mensaje = "Total Request " + str(totalRequest)+"\n"
    sys.stderr.write(mensaje)
    '''
    print("Endpoints to cache")
    print(dicEndCache)
    print("Endpoints to central")

    print(dicEndCentral)
    print("Endpoins and videos")

    print (dicEndVideo)

    '''
    #Cargamos el mejor
    if os.path.isfile(nombreMaximoAntiguo + 'mejor.json'):
        with open(nombreMaximoAntiguo + 'mejor.json') as data_file:
            mejorIndividuo = json.load(data_file)

    mejorFitness,temporal=calcularFitness(mejorIndividuo)
    #Hacemos el algoritmo genetico
    res=algoritmoGenetico()

    #print (mejorIndividuo)
    mejorIndividuo=aux.eliminarDuplicadosLista(mejorIndividuo)
    #print(mejorIndividuo)
    mejorIndividuo=eliminarNoCaben(mejorIndividuo)
    #print(mejorIndividuo)

    #Preparamos el resultado
    dicResultado={}
    for i in range(C):
        dicResultado[i]=[]

    for x in mejorIndividuo:
        dicResultado[x[0]].append(x[1])



    #Imprimimos el resultado
    print(len(dicResultado))
    for i in dicResultado:
        cadena=str(i)
        for j in range(len(dicResultado[i])):
            cadena=cadena+" "+str(dicResultado[i][j])

        print(cadena)





if __name__ == "__main__":
    # execute only if run as a script
    main()
