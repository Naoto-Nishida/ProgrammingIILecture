#include <stdio.h>

struct Person {
  char name[256];
  int birth;
};

union Data {
  char a;
  int b;
};

int main(void)
{
  struct Person person;
  union Data data;
    char c;
    char str[256];
    char str2[2][32];
    char *pc;
 
    int i;
    int iary[4];
    int *pi;
 
    float f;
    float fary[8];
    float *pf;
 
    double d;
    double dary[16];
    double *pd;
 
    /* 上で説明した通り、sizeof 演算子の返り値が unsigned long int なので
       printf には %d ではなく %lu を指定する */
 
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(char*) = %lu\n", sizeof(char*));
    printf("sizeof(c) = %lu\n", sizeof(c));
    printf("sizeof(str) = %lu\n", sizeof(str));
    printf("sizeof(str2) = %lu\n", sizeof(str2));
    printf("sizeof(pc) = %lu\n\n", sizeof(pc));
 
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(int*) = %lu\n", sizeof(int*));
    printf("sizeof(i) = %lu\n", sizeof(i));
    printf("sizeof(iary) = %lu\n", sizeof(iary));
    printf("sizeof(pi) = %lu\n\n", sizeof(pi));
 
    printf("sizeof(float) = %lu\n", sizeof(float));
    printf("sizeof(float*) = %lu\n", sizeof(float*));
    printf("sizeof(f) = %lu\n", sizeof(f));
    printf("sizeof(fary) = %lu\n", sizeof(fary));
    printf("sizeof(pf) = %lu\n\n", sizeof(pf));
 
    printf("sizeof(double) = %lu\n", sizeof(double));
    printf("sizeof(double*) = %lu\n", sizeof(double*));
    printf("sizeof(d) = %lu\n", sizeof(d));
    printf("sizeof(dary) = %lu\n", sizeof(dary));
    printf("sizeof(pd) = %lu\n\n", sizeof(pd));

    printf("sizeof(Person) = %lu\n", sizeof(person));
    printf("sizeof(Person.name) = %lu\n", sizeof(person.name));
    printf("sizeof(Person.birth) = %lu\n\n", sizeof(person.birth));

    printf("sizeof(Data) = %lu\n", sizeof(data));
    printf("sizeof(Data.a) = %lu\n", sizeof(data.a));
    printf("sizeof(Data.b) = %lu\n", sizeof(data.b));
    return 0;
}
