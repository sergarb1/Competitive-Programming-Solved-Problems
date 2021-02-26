#!/bin/sh
echo B
python3 mainAleatorio.py mejores/b_little_bit_of_everything.out 200000 < b_little_bit_of_everything.in > mejores/BRES.txt
echo C
python3 mainAleatorio.py mejores/c_many_ingredients.out 200 < c_many_ingredients.in > mejores/CRES.txt
echo D
python3 mainAleatorio.py mejores/d_many_pizzas.out 200 < d_many_pizzas.in > mejores/DRES.txt
echo E
python3 mainAleatorio.py mejores/e_many_teams.out 200 < e_many_teams.in > mejores/ERES.txt
