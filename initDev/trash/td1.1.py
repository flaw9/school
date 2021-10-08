def manipEntiers():
    m = -1
    while m < 50 or m > 100:
        m = int(input('Entrez un nombre entre 50 et 100: '))
        if m < 50 or m > 100:
            print('Le nombre doit être comprit entre 50 et 100.')
    n = int(m);
    m += 62 - 100 + 1
    m = n - m
    print(m)
    if m == 37:
        print('Le compte est bon.')
    else:
        print('Revoyez vos comptes !')

def main():
    manipEntiers()

if __name__ == "__main__":
    main()