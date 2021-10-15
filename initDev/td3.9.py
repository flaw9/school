def voyelles(chaine):
    count = 0
    for i in chaine:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'y' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U' or i == 'Y':
            count += 1
    return count

def main():
    c = list(map(str, input()))
    print(voyelles(c))

if __name__ == "__main__":
    main()