def rechercheDichotomie(tab: list, x: int) -> int:
    cpt = 0
    debut, fin = 0, len(tab) - 1
    while debut <= fin:
        m = (debut + fin) // 2
        if x == tab[m]:
            return m, cpt
        if x > tab[m]:
            cpt += 1
            debut = m + 1
        else:
            cpt += 1
            fin = m - 1

    return cpt

def main():
    for n in range(1,11):
        print(f"<tr>\n    <td>{n}</td>\n    <td>{2**n}</td>\n    <td>{rechercheDichotomie([i for i in range(2**n)],10000)}</td>\n    <td></td>\n</tr>")

if __name__ == "__main__":
    main()