def tablesMultiplication():
    x = int(input("Saisir un nombre: "))
    for i in range(1,11):
        print(f"{x} x {i} = {x*i}")
    return

def main():
    tablesMultiplication()

if __name__ == "__main__":
    main()