def methode_1():
    x = 1
    while x != 0:
        x = -1
        while x < 0:
            x = int(input("Entrez une valeur: "))
        if x > 0:
            a = int(x)
            for i in range(1, 100):
                a = 0.5 * (a + x/a)
            print(f"La racine carrée de {x} est {a}.")

def methode_2():
    x = int(input())

def main():
    # methode_1()
    methode_2()

if __name__ == "__main__":
    main()