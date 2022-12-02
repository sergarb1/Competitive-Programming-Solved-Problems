#!/usr/bin/python3


file_path = 'input02-01.in'

file_text = open(file_path, "r")

#A,X -> Rock
#B,Y -> Paper
#C,Z -> Scissor

totalPuntosTu=0

while True:
    line = file_text.readline().strip()
    strategy=line.split(" ")

    if not line:
        break
    puntosRival=0
    puntosTu=0

    rival=strategy[0]
    tu=strategy[1]

    # Puntos base rival
    if rival=="A":
        puntosRival=1
    elif rival=="B":
        puntosRival=2
    elif rival=="C":
        puntosRival=3

    # Puntos base tu
    if tu=="X":
        puntosTu=1
    elif tu=="Y":
        puntosTu=2
    elif tu=="Z":
        puntosTu=3


    if ( (rival=="A" and tu=="Y") or (rival=="B" and tu=="Z") or (rival=="C" and tu=="X")):
        puntosTu=puntosTu+6
    elif ( (rival=="A" and tu=="X") or (rival=="B" and tu=="Y") or (rival=="C" and tu=="Z")):
        puntosTu=puntosTu+3

    totalPuntosTu=totalPuntosTu+puntosTu

print(totalPuntosTu)