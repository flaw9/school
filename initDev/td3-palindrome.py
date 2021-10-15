def palindrome(liste):
    print(liste, liste[::-1])
    if liste[::-1] == liste:
        return True
    else:
        return False

def main():
    phrase = list(map(str, input().replace(' ', '')))
    print(palindrome(phrase))

if __name__ == "__main__":
    main()