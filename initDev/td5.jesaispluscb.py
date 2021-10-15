def maxDoubleLoop(t):
    d = 0
    for i in range(len(t)):
        for j in range(len(t)):
            dd = t[i] - t[j]
            if dd > d:
                d = dd
    return d

def main():
    # maxDoubleLoop()
    pass


if __name__ == "__main__":
    main()