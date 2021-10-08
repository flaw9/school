def main():
    n = -1
    while n < 0:
        n = int(input("Entrez un nombre entier strictemet positif: "))
    s = 0
    for i in range(n+1):
        s += 1/i
    print(f"La somme vaut: {s}")

if __name__ == "__main__":
    main()