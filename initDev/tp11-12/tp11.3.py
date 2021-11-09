def Lecture_Mnemo(fichier: str) -> list:
    Code_a_Executer = open(f"{fichier}", 'r').readlines()
    return Code_a_Executer

def Seg_Mnemo(x: int, Code_a_Executer: list) -> list:
    return Code_a_Executer[x].replace(',', ' ').replace('(', ' ').replace(')', ' ').split(' ')

def main():
    Code_a_Executer = Lecture_Mnemo('tp11-12/source.asm')
    for i in range(len(Code_a_Executer)):
        Champs_Code = Seg_Mnemo(i, Lecture_Mnemo('tp11-12/source.asm'))[:-1]
        print(Champs_Code)

if __name__ == "__main__":
    main()