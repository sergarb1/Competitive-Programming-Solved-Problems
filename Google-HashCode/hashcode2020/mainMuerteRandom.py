import random




def main():
    listaNegra={}
    
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



    

    #Nos cargamos 10% a boleo
    libreria=random.sample(libreria,int(len(libreria)*0.9))
    #FIN ENTRADA


    # ORDENAMOS POR MENOR TIEMPO SINGUP
    def ordenarBiblio(elementoNum):
        return int(elementoNum[1][1]*1000) - int(elementoNum[1][2])
    libreria.sort(key=ordenarBiblio,reverse=False)
    #FIN ORDENAR


    #Procesamos bibliotecas en orden
    diaEmpezar=0
    for elemento in libreria:
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
            return int(elementoNum[0])
        listaLibros.sort(key=ordenarLibros,reverse=True)
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