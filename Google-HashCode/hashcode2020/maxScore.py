import random



def calculaFitness(elemento):

    numLibreriaPro=elemento[0]
    restoLibreria=elemento[1]
        
    singup=restoLibreria[1]
    librosPorDia=restoLibreria[2]

    listaLibros=restoLibreria[3]

    suma=0
    #listaLibros=random.sample(listaLibros,int(len(listaLibros)*0.10))

    muestreo=min(10,len(listaLibros))

    listaLibros=random.sample(listaLibros,muestreo)
    for e in listaLibros:
        suma=suma+e[1]
    return suma


def main():
    listaNegra={}
    
    resultado=[]


    #Leemos la entrada
    B,L,D = map(int,input().split())
    booksScore= list(map(int,input().split()))

    suma=0
    for x in booksScore:
        suma=suma+x
    print(suma)
main()