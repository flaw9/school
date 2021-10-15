def sort_bubbles(array):
    for i in range(1,len(array)+1):
        for j in range(1,len(array)-i +1):
            if array[j-1] > array[j]:
                array[j-1], array[j] = array[j], array[j-1]
    return array

def main():
    t = list(map(int, input().split()))
    print(sort_bubbles(t))

if __name__ == "__main__":
    main()