v1 = [1, 2, 3, 4, 5, 6, 7, 8, 29]
v2 = [3, 2, 1, -5, 5, 0, 0, 1, 3]

media_v1 = 0
media_v2 = 0

for x in range(0, len(v1)):
  media_v1 += v1[x]
  media_v2 += v2[x]

print("Média de V1", len(v1), ": ", media_v1/len(v1), " Mediana: ", v1[len(v1) // 2])
print("Média de V2", len(v2), ": ", media_v2/len(v2), " Mediana: ", v2[len(v2) // 2])

# RESULTADO
# Média de V1 9 :  7.222222222222222  Mediana:  5
# Média de V2 9 :  1.1111111111111112  Mediana:  5