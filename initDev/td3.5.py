def main():
    nb, t = 1, []
    while nb != 0:
        nb = int(input("Saisir un nombre: "))
        t.append(nb)
    t.pop()

    nb = int(input("Saisir un nombre à supprimer: "))
    noc = 0
    for i in range(0, len(t)):
        if(t[i] == nb):
            noc += 1
        else: 
            t[i-noc] = t[i]
    for i in range(noc):
        t.pop()

        print(f"{noc} occurences de {nb} ont été trouvées dans t.")
        print(t)

if __name__ == "__main__":
    main()