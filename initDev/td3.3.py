def main():
    nb, t = 1, []
    while nb != 0:
        nb = int(input("Saisir un nombre: "))
        t.append(nb)
    nb = int(input("Saisir un nombre: "))
    pos = 0
    while pos < 1 or pos > len(t):
        pos = int(input("Saisir une position d'insertion (1 < pos < taille): "))
        pos -= 1
    for i in range(len(t)-1, pos-1, -1):
        t[i] = t[i-1]
    t[pos] = nb
    print(t)

if __name__ == "__main__":
    main()