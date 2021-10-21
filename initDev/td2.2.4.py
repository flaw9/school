def methode_1():
    n = -1
    while n < 0:
        n = int(input("Entrez un nombre entier strictemet positif: "))
    s = 0
    for i in range(n+1):
        s += 1/i
    print(f"La somme vaut: {s}")

def methode_2():
    n = -1
    while n < 0:
        n = int(input("Entrez un nombre entier strictemet positif: "))
    s = 0
    sgn = 1
    for i in range(n+1):
        s += sgn/i
        sgn = -sgn
    print(f"La somme vaut: {s}")

def main():
    # methode_1()
    # methode_2()
    return

if __name__ == "__main__":
    main()