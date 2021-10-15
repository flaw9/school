def main():
    chaine = list(map(str, input("Chaine de caractères à coder: ")))
    chaine2 = ""
    for i in chaine:
        if i != ' ' and i != 'Z' and i != 'z':
            chaine2 = f"{chaine2}{chr( ord(i) + 1)}"
        elif i == 'z':
            chaine2 = f"{chaine2}a"
        elif i == 'Z':
            chaine2 = f"{chaine2}A"
        else:
            chaine2 = f"{chaine2} "

    print(chaine2)

if __name__ == "__main__":
   main()