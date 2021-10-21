from math import sqrt

def resolve(a, b, c):
    s = []
    ns = 0
    if a == 0:
        if b == 0:
            if c == 0:
                ns = -1
        else:
            s.append( (-c) / b )
            ns = 1
    else:
        delta = b**2 - (4 * a * c)
        if delta > 0:
            s.append( - (b - sqrt(delta)) / (2 * a) )
            s.append( - (b + sqrt(delta)) / (2 * a) )
            ns = 2
        else:
            s.append( (-b) / (2 * a) )
    return ns, s

def main():
    """Récupération de toutes les variables, appel de la fonction de résolution et affichage du résultat."""
    a = int(input("Entrez le coefficient de degré 2: "))
    b = int(input("Entrez le coefficient de degré 1: "))
    c = int(input("Entrez le coefficient constant: "))
    resultat = resolve(a, b, c)
    print(f"L'équation possède {resultat[0]} solution(s).")
    if resultat[0] > 0:
        for i in range(len(resultat[1])):
            print(f"Résultat n°{i+1} = {resultat[1][i]}")
    else:
        print(f"L'équation n'a pas de solution.")


if __name__ == "__main__":
    main()