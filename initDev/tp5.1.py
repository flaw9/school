def est_la(n: int, t: list, v: int):
    for i in range(n):
        if t[i] == v:
            return True
    return False

def prem_occ(n: int, t: list, v: int):
    for i in range(n):
        if t[i] == v:
            return i
    return -1

def sequence(n: int, t: list, deb: int):
    while deb < n-1 and t[deb+1] >= t[deb]:
        deb += 1
    return deb+1

def diametre(t: list, n: int):
    return max(t) - min(t)

def main():
    t = []
    nbCases = -1
    while nbCases <= 0 or nbCases > 100:
        nbCases = int(input("Donnez un nombre entre 0 et 100: "))
        if nbCases <= 0 or nbCases > 100:
            print("Le nombre doit être compris entre 0 et 100 !")
    for _ in range(nbCases):
        t.append(int(input()))
    
    # print(est_la(nbCases, t, int(input())))
    # print(prem_occ(nbCases, t, int(input())))
    # print(sequence(nbCases, t, int(input())-1))
    # print(diametre(t, nbCases))

    


if __name__ == "__main__":
    main()