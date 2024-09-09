#!/usr/local/bin/python3

#=================================
#  Programa de prueba en python3 
#=================================
import numpy as np
import time

#==============
#  Constantes 
#==============
VEC_LEN = 1000000
AVERAGING = 1000

#===================================
#  Llena a y b con números al azar 
#===================================
a = np.random.rand(VEC_LEN)
b = np.random.rand(VEC_LEN)

#============================
#  Producto punto con numpy 
#============================
tic = time.time()
for i in range(AVERAGING):
  c = np.dot(a,b)
toc = time.time()

print("c: " + str(c))
print("Vectorized version: " + str ((toc - tic) * 1000 / AVERAGING) + "ms")

c = 0

#==============================
#  Producto punto con objetos 
#==============================
tic = time.time()
for i in range(VEC_LEN):
  c += a[i]* b[i]
toc = time.time()

print("c: " + str(c))
print("For loop: " + str ((toc-tic) * 1000) + "ms")
