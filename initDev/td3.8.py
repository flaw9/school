def main():
    n = int(input("Combien de caractères ?: "))
    chaine = list(map(str, input("Chaine ade caractères à coder: ")))
    chaine2 = ""
    for i in chaine:
        chaine2 = f"{chaine2}{chr( ord(i) + n)}"
    print(chaine2)

if __name__ == "__main__":
   main()