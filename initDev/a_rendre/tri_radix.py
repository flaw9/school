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
    t = [1,2,3,4,5]
    print(tri_radix(t))

if __name__ == "__main__":
    main()