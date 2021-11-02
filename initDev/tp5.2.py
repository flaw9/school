def main():
    t = [i for i in range(2, int(input()))]
    for i in t:
        for j in t[i:]:
            if j%i == 0:
                t.remove(j)
    print(t)

if __name__ == "__main__":
    main()