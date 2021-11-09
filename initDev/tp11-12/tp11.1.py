from typing import Iterable

def rechercheNaive(t: list, res: int) -> int:
    i = 0
    while i < len(t)-1 or t[i] < res:
        i += 1
        if t[i] == res:
            return i
    return -1

def main():
    print(rechercheNaive([1,2,3,4,5,6,7,8,9,10,13,15,17,19],15))

if __name__ == "__main__":
    main()