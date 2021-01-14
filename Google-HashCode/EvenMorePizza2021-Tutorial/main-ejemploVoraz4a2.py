#!/usr/bin/python3

#Funcion que imprime la solucion a enviar al juez
def imprimirsolucion(entregas):
    
    #Imprimimos numero de envios
    print(len(entregas))
    for entre in entregas:
        #Imprimimos cada envio generando una cadena y finalmente imprimiendola
        #En primer lugar, ponemos el envio si va a un grupo de 4, 3 o 2
        cad=str(entre[0])
        #Recorremos la lista para imprimir que pizzas iban en ese envio
        for elemento in entre[1:]:
            cad=cad+" "+str(elemento)
        #Imprimimos la solucion
        print(cad)


#Programa principal
def main():
    #Declaramos variables para leer total de pizzas y total de cada tipo de equipo
    nPizzas=0
    nEq2=0
    nEq3=0
    nEq4=0
    # Leemos numero pizzas, equipos de 2, 3 y 4 miembros
    nPizzas, nEq2, nEq3, nEq4= map(int, input().split())
    #Declaramos una lista con las pizzas que leeremos
    pizzas = []
    # Leemos todas las pizzas. Las metemos en una lista cada una, ignorando el primer elemento
    # El motivo de ignorar el primer elemento, es que nos dice cuantos ingredientes son, pero por 
    # ahorrar espacio no lo metemos y siempre podemos calcular con la funcion "len"
    for _ in range(nPizzas):
        pizzas.append(input().split()[1:])

    #Lista que contendrá el resultado de pizzas asignadas
    res=[]

    #Mientras queden Pizzas y grupos, voy creando entregas
    pizzaActual=0

    
    #Asignamos pizzas primero los grupos de 4
    while(pizzaActual+4<=nPizzas and nEq4>0):
        #Añadimos el resultado
        res.append([4,pizzaActual,pizzaActual+1,pizzaActual+2,pizzaActual+3])
        pizzaActual=pizzaActual+4
        nEq4=nEq4-1
        
    #Luego grupos de 3
    while(pizzaActual+3<=nPizzas and nEq3>0):
        res.append([3,pizzaActual,pizzaActual+1,pizzaActual+2])
        pizzaActual=pizzaActual+3
        nEq3=nEq3-1

    #ultimo grupos de 2
    while(pizzaActual+2<=nPizzas and nEq2>0):
        res.append([2,pizzaActual,pizzaActual+1])
        pizzaActual=pizzaActual+2
        nEq2=nEq2-1
    

    #imprimimos el resultado de res
    imprimirsolucion(res)





# Codigo a ejecutar inicial
main()

