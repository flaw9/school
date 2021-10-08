def methode_1():
    x = 1
    while x != 0:
        x = -1
        while x < 0:
            x = int(input("Entrez une valeur: "))
        if x > 0:
            a = int(x)
            for i in range(1, 101):
                a = 0.5 * (a + x/a)
            print(f"La racine carrée de {x} est {a}.")

def methode_2():
    '''J'ai pas réellement compris l'intérêt ni le fonctionnement de cette fonction mais bon...'''
    x = int(input("Entrez une valeur: "))
    while x < 0:
        x = int(input("Entrez une valeur: "))
    if x != 0:
        a = int(x)
        for i in range(1, 101):
            a = 0.5 * (a + x/a)
        print(f"La racine carrée de {x} est {a}.")
    while x != 0:
        x = int(input("Entrez une valeur: "))
        while x < 0:
            x = int(input("Entrez une valeur: "))
        if x != 0:
            a = int(x)
            for i in range(1, 101):
                a = 0.5 * (a + x/a)
            print(f"La racine carrée de {x} est {a}.")

def methode_3():
    pass

def main():
    # methode_1()
    # methode_2() # je ne sais pas ce que c'est que cette fonction ...
    methode_3()

if __name__ == "__main__":
    main()