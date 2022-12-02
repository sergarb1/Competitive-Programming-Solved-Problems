#!/usr/bin/python3


file_path = 'input.in'

file_text = open(file_path, "r")

acumCalorias=0
maxCalorias=0
while True:
    line = file_text.readline()
    
    #Si la linea no es vacia
    if line.strip():
        acumCalorias=acumCalorias+int(line)
        if acumCalorias>maxCalorias:
            maxCalorias=acumCalorias
    else:
        acumCalorias=0

    if not line:
        break
print(maxCalorias)
file_text.close()