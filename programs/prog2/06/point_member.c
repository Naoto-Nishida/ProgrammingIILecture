#include <stdio.h>
#include <string.h>
 
typedef struct Person {
    char *name; /* メンバ変数がポインタ */
    int age;
} Person;
 
int main(void)
{
    Person p1, p2;
    char name[256];
 
    /* 文字列に printf できる関数 */
    sprintf(name, "%s", "Yamada");
 
    p1.name = name;
 
    p2 = p1;
 
    printf("name of p1: %s\n", p1.name);
    printf("name of p2: %s\n", p2.name);
 
    /* name に入っている値を変更 */
    strcpy(name, "Yamamoto");
    printf("\nname changed\n\n");
 
    printf("name of p1: %s\n", p1.name);
    printf("name of p2: %s\n", p2.name);
 
    return 0;
}
