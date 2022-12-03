#!/usr/bin/python3

def buscarComun(l1,l2):

    for x in l1:
        if x in l2:
            return x
    return None

def obtenerPrioridad(c):

    if c - ord('a')>=0:
        return c - ord('a')+1
    if c - ord('A')>=0:
        return c - ord('A')+27
    


file_path = 'input03-01.in'
#file_path = 'prueba.txt'

file_text = open(file_path, "r")

sumaValor=0

while True:
    line = file_text.readline().strip()

    if not line:
        break

    saco1=line[0:int(len(line)/2)]
    saco2=line[int(len(line)/2):]

    comun=buscarComun(saco1,saco2)
    #print(comun)
    valor=obtenerPrioridad(ord(comun))
    #print(valor)
    sumaValor=sumaValor+valor
    #print(saco1)
    #print(saco2)
print(sumaValor)
