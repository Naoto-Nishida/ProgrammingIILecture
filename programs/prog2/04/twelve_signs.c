#include <stdio.h>
 
void ne(void) { printf("ね（子）\n"); }
void ushi(void) { printf("うし（丑）\n"); }
void tora(void) { printf("とら（寅）\n"); }
void u(void) { printf("う（卯）\n"); }
void tatsu(void) { printf("たつ（辰）\n"); }
void mi(void) { printf("み（巳）\n"); }
void uma(void) { printf("うま（午）\n"); }
void hitsuji(void) { printf("ひつじ（未）\n"); }
void saru(void) { printf("さる（申）\n"); }
void tori(void) { printf("とり（酉）\n"); }
void inu(void) { printf("いぬ（戌）\n"); }
void i(void) { printf("い（亥）\n"); }
 
int main(void)
{
    int year;
    void (*p[])(void) = { ne, ushi, tora, u, tatsu, mi, uma, hitsuji, saru, tori, inu, i };

    printf("INput a year>");
    scanf("%d", &year);
    printf("西暦%d年：", year);
    
#ifdef MACRO
    switch ((year+8) % 12) {
    case 0: ne(); break;
    case 1: ushi(); break;
    case 2: tora(); break;
    case 3: u(); break;
    case 4: tatsu(); break;
    case 5: mi(); break;
    case 6: uma(); break;
    case 7: hitsuji(); break;
    case 8: saru(); break;
    case 9: tori(); break;
    case 10: inu(); break;
    case 11: i(); break;
    }
#endif

    (*p[(year+8) % 12])();
     
    return 0;
}
