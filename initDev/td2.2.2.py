def fdsc(t):
    '''fdsc = Fonction Du Second Degré'''
    return 2 * t**3 - t**2 - 37 * t + 36

def main():
    t = -5
    minimum = fdsc(t)
    maximum = int(minimum)
    while t < 5:
        t += 0.25
        f = fdsc(t)
        if f < minimum:
            minimum = f
        elif f > maximum:
            maximum = f
    print(f"La valeur minimale est: {minimum}")
    print(f"La valeur maximale est: {maximum}")

if __name__ == "__main__":
    main()