def tri_compteur(array: list):
    unites = [0 for _ in range(10)]
    while len(array) > 0:
        if array[-1] > 10 or array[-1] < 0:
            return "Tableau incorrect."
        else:
            unites[array.pop()] += 1
    for j in range(len(unites)):
        while unites[j] > 0:
            array.append(j)
            unites[j] -= 1
    return array

def main():
    print(tri_compteur(t))

if __name__ == "__main__":
    main()