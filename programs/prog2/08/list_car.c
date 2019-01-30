#include <stdio.h>
#include <stdlib.h>
 
typedef struct Car {
    int num;
    double gas;
    struct Car *next;   /* struct Car 型のポインタ */
} Car;
 
int main(void)
{
    Car *car0, *car1, *car2;
    Car *pcar;

    car0 = (Car *)malloc(sizeof(Car));
    car1 = (Car *)malloc(sizeof(Car));
    car2 = (Car *)malloc(sizeof(Car));
 
    *(car0) = (Car){ 1234, 25.5, car1 };
    *car1 = (Car){ 4576, 52.2, car2 };
    *car2 = (Car){ 7890, 20.5, NULL };
     
    for (pcar = car0; pcar != NULL; pcar = pcar->next)
    {
        printf("car number: %d, gas: %f\n", pcar->num, pcar->gas);
    }


    free(car0);
    free(car1);
    free(car2);
 
    return 0;
}
