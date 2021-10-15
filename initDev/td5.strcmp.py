def strcmp(s1, s2):
    i = 0
    while s1[i] != 0:
        if s1[i] < s2[i]:
            return 1
        elif s1[i] > s2[i]:
            return -1
        else:
            i += 1
    if s1[i] < s2[i]:
        return 1
    elif s1[i] > s2[i]:
        return -1
    else:
        return 0

def main():
    su, sd = str(input("Chaine n°1: ")), str(input("Chaine n°2: "))
    print(strcmp(su, sd))

if __name__ == "__main__":
    main()