def methodOne():
    i = 1
    while (i < 100) and ( (i%2 != 1) or (i%3 != 2) or (i%4 != 3) or (i%5 != 4) ):
        i += 1
    if (i < 100):
        print(f"1. La solution est {i}")
    else:
        print(f"Il n'existe pas de solution dans l'intervalle [1, 100]")

def methodTwo():
    i = 1
    while i<100:
        if (i%2 == 1) and (i%3 == 2) and (i%4 == 3) and (i%5 == 4):
            print(f"2. La solution est {i}")
            return
        i += 1
    print(f"Il n'existe pas de solution dans l'intervalle [1, 100]")

def methodThree():
    limit, i = int(input("Entrez la limite: ")), 1
    while i < 100:
        t, k = True, 2
        while k <= limit:
            t = (t and (i%k == k - 1))
            k += 1
        if t:
            print(f"3. La solution est {i}")
            return
        i += 1
    print(f"Il n'existe pas de solution dans l'intervalle [1, 100]")

def main():
    methodOne()
    methodTwo()
    methodThree()

if __name__ == "__main__":
    main()