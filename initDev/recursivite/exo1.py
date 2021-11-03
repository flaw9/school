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

def reverse(s: str) -> str:
    if len(s) == 1:
        return s
    else:
        return f"{s[-1]}{reverse(s[0:-1])}"

def fibo(n: int) -> int:
    return n

def main():
    # factorielle_recursive(int(input()))
    # print(puissance_iterative(int(input()), 2))
    # print(puissance_recursive(int(input()), 2))
    print(reverse(str(input())))

if __name__ == "__main__":
    main()