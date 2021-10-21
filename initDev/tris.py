def tri_bulles(array: list):
    for i in range(1,len(array)+1):
        for j in range(1,len(array)-i +1):
            if array[j-1] > array[j]:
                array[j-1], array[j] = array[j], array[j-1]
    return array

def tri_insertion(array: list):
    for i in range(len(array)):

        pos = 0
        while array[pos] < array[i] and pos < i:
            pos += 1
        array.insert(pos, array.pop(i))
    return array

def tri_selection(array: list):
    for i in range(len(array)):
        mini = i
        for j in range(i, len(array)):
            if array[j] < array[mini]:
                mini = j
        array[mini], array[i] = array[i], array[mini]
    return array

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

def tri_radix(array: list):
    lenBigger = len(str(max(array)))
    for k in range(lenBigger):
        tat = [[] for _ in range(10)]
        for i in array:
            if k >= len(str(i)):
                tat[0].append(i)
            else:
                tat[int(str(i)[::-1][k])].append(i)
        array = []
        for j in range(len(tat)):
            while len(tat[j]) > 0:
                array.append(tat[j].pop(0))
    return array


def main():
    t = list(map(int, input().split()))
    # print(tri_bulles(t))
    # print(tri_insertion(t))
    # print(tri_selection(t))
    # print(tri_compteur(t))
    # print(tri_radix(t))

if __name__ == "__main__":
    main()