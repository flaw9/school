#include <stdio.h>

int main() {
    char c = 'a';
    unsigned char uc = 0;
    short s = -1;
    unsigned short us=65535;
    int i = 0;
    unsigned int ui = 0;
    long int li = 0;
    float f = 0.5;
    double d = 1e10;
    long double ld = 5e-3;

    printf("char\t\t: valeur=%c, taille=%ld\n", c, sizeof(c));
    printf("unsigned char\t\t: valeur=%d, taille=%ld\n", uc, sizeof(uc));
    printf("short\t\t: valeur=%d, taille=%ld\n", c, sizeof(s));
    printf("unsigned short\t\t: valeur=%d, taille=%ld\n", c, sizeof(us));
    printf("int\t\t: valeur=%d, taille=%ld\n", c, sizeof(i));
    printf("unsigned int\t\t: valeur=%d, taille=%ld\n", c, sizeof(ui));
    printf("long int\t\t: valeur=%u, taille=%ld\n", c, sizeof(li));
    printf("float\t\t: valeur=%ld, taille=%ld\n", c, sizeof(f));
    printf("double\t\t: valeur=%f, taille=%ld\n", c, sizeof(d));
    printf("long double\t\t: valeur=%f, taille=%ld\n", c, sizeof(ld));
}
