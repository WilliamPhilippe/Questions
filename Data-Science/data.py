# ------------------------------------------------------------------------------------
# QUESTÃO 4 a) e b)
# - - - 

# LUCRO por ano (1 - 18) em milhões de reais

v1 = [1, 2, 3, 4, 5, 6, 7, 8, 29, 1, 32, 3, 24, 15, 16, 71, 82, 29, 3]
v2 = [3.1, 2.1, 1.1, -5.1, 2.10, 0, 0, 1.1, 3.1, 3.1, 2.1, 1.1, -2.10, 2.10, 0, 0, 10.1, 3.1, 0.3]

media_v1 = 0
media_v2 = 0

for x in range(0, len(v1)):
  media_v1 += v1[x]
  media_v2 += v2[x]

# Resposta a):
print("Média de V1", len(v1), ": ", media_v1/len(v1), " Mediana: ", v1[len(v1) // 2])
# Média de V1 19 :  17.94736842105263  Mediana:  1

# Resposta b):
print("Média de V2", len(v2), ": ", media_v2/len(v2), " Mediana: ", v2[len(v2) // 2])
# Média de V2 19 :  1.436842105263158  Mediana:  3.1



# ------------------------------------------------------------------------------------
# QUESTÃO 5 a) e b)
# - - - 
import matplotlib.pyplot as plt
import numpy as np

plt.style.use('fivethirtyeight')

plt.hist(v2, bins=6, edgecolor='black')

plt.title('Vendas por ano (V2)')
plt.xlabel('Milhões de reais')
plt.ylabel('Quantidades')

plt.tight_layout()

plt.show()