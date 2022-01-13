#!/bin/bash
chmod +x *.py

./$1 < a_an_example.in > a_an_example.out
./$1 < b_basic.in > b_basic.out
./$1 < c_coarse.in > c_coarse.out
./$1 < d_difficult.in > d_difficult.out
./$1 < e_elaborate.in > e_elaborate.out

