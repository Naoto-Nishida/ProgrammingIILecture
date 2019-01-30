#include <stdio.h>
#include <string.h>
  
typedef struct Person {
    char name[256];
    int age;
} Person;
 
void SetPerson( /* 自分で実装 */ );
void PrintPerson( /* 自分で実装 */ );
void CopyPerson( /* 自分で実装 */ );
 
int main(void)
{
    Person p1, p2;
    char name[256];
 
    /* 値をセット */
    printf("Person 1 set\n");
    SetPerson( "Yamada", 41, p1 );   /* 関数の引数として "Yamada", 41 を与える…ハードコーディングでよい */
 
    PrintPerson( p1 ); /* 構造体のメンバ変数を printf 関数で出力 */
    putchar('\n');
 
    printf("Person 2 copied\n");
    CopyPerson( p1, p2 );  /* 2 つの構造体の一方のメンバ変数をもう一方のメンバ変数にコピー */
 
    PrintPerson( p2 );
    putchar('\n');
     
    printf("Person 2 set\n");           /* Person2の情報を"Nagata", 63に書き換え */
    SetPerson( "Nagata", 63, p2 );
    PrintPerson( p2 );
  
    return 0;
}
 
void SetPerson( char name, int age, Person p )
{
  p.name = name;
  p.age = age;
}
 
void PrintPerson( Person p )
{
  printf("name: %s", p.name);
  printf("age: %d", p.age);
}
 
void CopyPerson( Person p1, Person p2 )
{
  p2 = p1;
}
