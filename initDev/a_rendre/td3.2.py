def main():
    nb, t = 1, []
    while nb != 0:
        nb = int(input("Saisir un nombre: "))
        t.append(nb)
    t.pop()
    taille = len(t)
    print(f"Le tableau t contient {taille} element(s).")
    nb = int(input("Saisir un nombre: "))
    noc = 0
    for i in range(len(t)):
        if t[i] == nb:
            print(f"{nb} trouvé à la position {i}")
            noc += 1
    print(f"{nb} apparait {noc} fois dans le tableau t.")

if __name__ == "__main__":
    main()