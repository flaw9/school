def main():
    nb, t = 1, []
    while nb != 0:
        nb = int(input("Saisir un nombre: "))
        t.append(nb)
    t.pop()
    taille = len(t)
    print(f"Le tableau t contient {taille} element(s).")

    petit = {'v': t[0], 'i': 0}
    grand = {'v': t[0], 'i': 0}
    for i in range(1, len(t)):
        if t[i] < petit['v']:
            petit = {
                'v': t[i],
                'i': i
            }
        if t[i] > grand['v']:
            grand = {
                'v': t[i],
                'i': i
            }
    print(f"La plus petite valeur du tableau est {petit['v']} enregistré à l'indice {petit['i']}")
    print(f"La plus grande valeur du tableau est {grand['v']} enregistré à l'indice {grand['i']}")

if __name__ == "__main__":
    main()