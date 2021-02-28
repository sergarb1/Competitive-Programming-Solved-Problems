#!/usr/bin/python3

import random

listaNegra={}

def calculaFitness(elemento):

    numLibreriaPro=elemento[0]
    restoLibreria=elemento[1]
        
    singup=restoLibreria[1]
    librosPorDia=restoLibreria[2]

    listaLibros=restoLibreria[3]

    suma=0
    #listaLibros=random.sample(listaLibros,int(len(listaLibros)*0.10))

    #muestreo=min(500,len(listaLibros))


    #listaLibros=random.sample(listaLibros,muestreo)
    cuenta=0
    lista=[]
    for e in listaLibros:
        if(e[1] not in listaNegra):
            suma=suma+e[0]
    
    return int(suma/singup)


def main():
    global listaNegra
    
    resultado=[]


    #Leemos la entrada
    B,L,D = map(int,input().split())
    booksScore= list(map(int,input().split()))
    libreria=[]
    for x in range(L):
        libreria.append(list(map(int,input().split())))    
        booksTMP=list(map(int,input().split()))
            #Anayado la posicion para que no se pierda
        tmpB=[]
        for y in range(len(booksTMP)):
            tmpB.append([booksScore[booksTMP[y]],booksTMP[y]])
        booksTMP=tmpB[:]

        libreria[x].append(booksTMP)


    #Anayado la posicion para que no se pierda
    tmp=[]
    for x in range(len(libreria)):
        tmp.append([int(x),libreria[x]])
    libreria=tmp[:]
    #FIN ENTRADA


    booksRareza = [0] * B

    #Calculamos rareza
    for e in libreria:
        restoLibreria=e[1]
        listaLibros=restoLibreria[3]
        for x in listaLibros:
            booksRareza[x[1]]=booksRareza[x[1]]+1


    #Procesamos bibliotecas en orden
    diaEmpezar=0

    while (len(libreria)):
        maximo=-1
        elemento=[]
        for e in libreria:
            f=calculaFitness(e)
            if(f>maximo):
                maximo=f
                elemento=e
        if(maximo==-1):
            break
        #Me cargo el candidato de la lista
        libreria.remove(elemento)


        numLibreriaPro=elemento[0]
        restoLibreria=elemento[1]
        
        singup=restoLibreria[1]
        librosPorDia=restoLibreria[2]

        listaLibros=restoLibreria[3]

        #Comprobar lista negra
        valido=False
        for x in listaLibros:
            if x[1] not in listaNegra:
                valido=True
                break
        if(valido==False):
            continue
        # Fin de comprobar todo lista negra

        #diaEmpezar lo actualizo
        diaEmpezar=diaEmpezar+singup
        cuantosDiasTenemos=D-diaEmpezar

        #Comprobar quedan dias
        if(cuantosDiasTenemos<=0):
            break

        # ORDENAMOS POR MENOR TIEMPO SINGUP
        def ordenarLibros(elementoNum):
            return int(booksRareza[elementoNum[1]])
        listaLibros.sort(key=ordenarLibros,reverse=False)
        #print(listaLibros)
        #print(resultado)
        numLibroActual=0
        solucionLibros=[]


        for days in range(cuantosDiasTenemos):
            for intentos in range(librosPorDia):
                if numLibroActual>=len(listaLibros):
                        break
                while(listaLibros[numLibroActual][1] in listaNegra):
                    numLibroActual=numLibroActual+1
                    #print("Libro actual "+str(numLibroActual))
                    if numLibroActual>=len(listaLibros):
                        break
                if numLibroActual>=len(listaLibros):
                    break
                #Encuentro un libro que no este en la lista negra
                solucionLibros.append(listaLibros[numLibroActual])
                #print(listaLibros[numLibroActual][1])
                listaNegra[listaLibros[numLibroActual][1]]="True"
                numLibroActual=numLibroActual+1

            if numLibroActual>=len(listaLibros):
                break
        #anyado a la solucion
        #print(solucionLibros)
        resultado.append([numLibreriaPro,solucionLibros])




    
    #Imprimimos cuantas bibliotecas
    print(len(resultado))
    for x in range(len(resultado)):
        print(str(resultado[x][0])+ " "+str(len(resultado[x][1])))
        cad=""
        for y in range(len(resultado[x][1])):
           cad=cad+" "+str(resultado[x][1][y][1])
        print(cad.strip())

main()