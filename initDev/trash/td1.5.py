def main():
    n = int(input("Entrez un nombre: "))
    listeEntiers = [int(input(f"Entrez la valeur {i+1}/{n}: ")) for i in range(n)]
    print(f"La plus petite valeur est {min(listeEntiers)}\nLa plus grande valeur est {max(listeEntiers)}")

if __name__ == "__main__":
    main()