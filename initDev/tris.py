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

def main():
    t = list(map(int, input().split()))
    # print(tri_bulles(t))
    # print(tri_insertion(t))
    # print(tri_selection(t))

if __name__ == "__main__":
    main()