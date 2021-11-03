import timeit

def LireDansIntervalle( imin: int, imax: int) -> int:
    ret = int(input())
    while ret < imin or ret > imax:
        print(f"Le nombre doit être comprit entre {imin} et {imax}")
        ret = int(input())
    return ret

def factorielle_iterative(n: int) -> int:
    s = 1
    for i in range(1,n+1):
        s *= i
    return s

def factorielle_recursive(n: int) -> int:
    print(f"Appel à factorielle {n}")
    if n <= 1:
        print(f"factorielle {n} retourne sa valeur 1")
        return 1
    else:
        F=n*factorielle_recursive(n-1)
        print(f"factorielle {n} retourne sa valeur {F}")
        return(F)

def puissance_iterative(x: (float or int), n: int) -> (float or int):
    for i in range(1,n):
        x *= x
    return x

def puissance_recursive(x: (float or int), n: int) -> (float or int):
    print(f"Appel à {x} puissance {n}")
    if n == 1:
        print(f"{x} puissance {n} retourne sa valeur {x}")
        return x
    else:
        P = x * puissance_recursive(x, n-1)
        print(f"{x} puissance {n} retourne sa valeur {P}")
        return(P)

def reverse_iterative(s: str) -> str:
    reverse = ""
    for i in range(0, len(s)):
        reverse = s[i]+reverse
    return reverse

def reverse_recursive1(s: str) -> str:
    if len(s) == 2:
        return s[-1] + s[0]
    else:
        return s[-1] + reverse_recursive1(s[1:-1]) + s[0]

def reverse_recursive2(s: str) -> str:
    if len(s) == 1:
        return s
    else:
        return f"{s[-1]}{reverse_recursive2(s[0:-1])}"

def fibo(n: int) -> int:
    if n == 1 or n == 2:
        return 1
    else:
        return fibo(n-1)+fibo(n-2)

def main():
    # factorielle_iterative(int(input()))
    # factorielle_recursive(int(input()))
    # print(puissance_iterative(int(input()), 2))
    # print(puissance_recursive(int(input()), 2))
    # print(reverse_iterative(str(input())))
    # print(reverse_recursive(str(input())))
    # print(fibo(int(input())))
    s = str(input())
    # print(reverse_iterative(s))
    print(reverse_recursive1(s))
    print(reverse_recursive2(s))
    # print(timeit.timeit(f"reverse_iterative('{s}')", number = 1000000, globals=globals())) #
    # print(timeit.timeit(f"reverse_recursive1('{s}')", number = 1000000, globals=globals())) #
    # print(timeit.timeit(f"reverse_recursive2('{s}')", number = 1000000, globals=globals())) #

if __name__ == "__main__":
    main()
