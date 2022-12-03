#!/usr/bin/python3

def buscarComun(l1,l2,l3):

    for x in l1:
        if x in l2 and x in l3:
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
    line1 = file_text.readline().strip()
    if not line1:
        break
    line2 = file_text.readline().strip()
    if not line1:
        break
    line3 = file_text.readline().strip()
    if not line1:
        break

    comun=buscarComun(line1,line2,line3)
    print(comun)
    valor=obtenerPrioridad(ord(comun))
    #print(valor)
    sumaValor=sumaValor+valor
    #print(saco1)
    #print(saco2)
print(sumaValor)
