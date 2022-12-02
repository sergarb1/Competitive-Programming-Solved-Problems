#!/usr/bin/python3


file_path = 'input01-01.in'

file_text = open(file_path, "r")

acumCalorias=0
maxCalorias=0

totales=[]

while True:
    line = file_text.readline()
    
    #Si la linea no es vacia
    if line.strip():
        acumCalorias=acumCalorias+int(line)
        if acumCalorias>maxCalorias:
            maxCalorias=acumCalorias
    else:
        totales.append(acumCalorias)
        acumCalorias=0

    if not line:
        break

totales.sort(reverse=True)
print(totales)

print(str(int(totales[0])+int(totales[1])+int(totales[2])))
file_text.close()