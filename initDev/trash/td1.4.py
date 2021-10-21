P = [2, 3, 5, 7, 9, 11, 13, 17, 23, 29, 31, 37, 41, 43, 47]
n = -1
while(n <= 0) or (n > 50):
    n = int(input("Entrer un nombre strictement positif inférieur a 50: "))
    if n <= 0 or n > 50:
        print("La valeur est incorrecte !")
i = 0
while(i <= len(P)) & (n > 1):
    while(n%P[i] == 0):
        print(P[i])
        n = n/P[i]
    i += 1