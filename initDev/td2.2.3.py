from math import e


def methode_1():
    x = -1
    while x != 0:
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
    tol = 1 * e - 2
    x = -1
    while x < 0:
        x = int(input("Entrez une valeur: "))
    if x > 0:
        a = int(x)
        aprev = a - (tol + 1)
        while abs(a - aprev) > tol:
            aprev = a
            a = 0.5 * (a + x/a)
        print(f"La racine carrée de {x} est {a}.")

def main():
    # methode_1()
    # methode_2() # je ne sais pas ce que c'est que cette fonction ...
    methode_3()

if __name__ == "__main__":
    main()