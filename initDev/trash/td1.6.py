def main():
    xMax = 100/10
    x = 0
    while x <= xMax:
        vMax = (100-10*x) / 5
        v = 0
        while v <= vMax:
            r = (100 - 10*x - 5*v)/2
            print(f"1€ = ({x}x10 cents) + ({v}x5 cents) + ({r}x2 cents)")
            v += 2
        x += 1

if __name__ == "__main__":
    main()