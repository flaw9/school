def voyelles_ver1(chaine):
    count = 0
    for i in chaine:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'y' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U' or i == 'Y':
            count += 1
    return count

def voyelles_ver2(chaine):
    count = 0
    voyelles = {
        'a': 1,
        'e': 1,
        'i': 1,
        'o': 1,
        'u': 1,
        'y': 1,
        'A': 1,
        'E': 1,
        'I': 1,
        'O': 1,
        'U': 1,
        'Y': 1
    }
    for i in chaine:
        count += voyelles.get(i, 0)
    return count

def main():
    c = list(map(str, input()))
    print(voyelles_ver1(c))
    print(voyelles_ver2(c))

if __name__ == "__main__":
    main()