#!/bin/bash
X=0
while [ $X -lt 1000 ]; do
	let X=X+1
	echo Iteracion $X
	./algoritmoGeneticoPartirFilasColumnas.py < big.in big.out
done
