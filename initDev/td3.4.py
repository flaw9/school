def main():
    nb, t = 1, []
    while nb != 0:
        nb = int(input("Saisir un nombre: "))
        t.append(nb)
    t.pop()
    pos = 0
    while pos < 1 or pos > len(t):
        pos = int(input("Saisir la position de l'élément à supprimer: "))
    i = int(pos)
    while i < len(t)-1:
        t[i] = t[i+1]
        i += 1
    print(t)

if __name__ == "__main__":
    main()