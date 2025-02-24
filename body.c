#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "Russian"); //добавляем локализацию

    int hm = 0;
    printf("Пожалуйста, укажите преполагаемое количество элементов в множестве (от 1 до 1000): ");

    while (hm>1000 || hm<1) //заставили задать длину будущего множества в переменной hm
    {
        hm = check_num();
    }


    if (hm>10)
    {
        printf("\nДовольного много элементов!\n");
        printf("Ввести вручную или заполнить на основе какого-либо закона?\n");

        int choose1 = 0;

        while (choose1<1 || choose1>2)
        {
            printf("Введите 1 чтобы заполнить в ручную\n");
            printf("Введите 2 чтобы заполнить по закону\n");

            while (choose1 != 1 && choose1 != 2)
            {
                choose1 = check_num();
                if (choose1 != 1 && choose1 != 2) {
                    printf("Неверное число\n");
                }
            }

        if (choose1 == 1)
        {
            rabota_s_mn(hm);

        } else if (choose1 == 2)
        {
            arifm_prog_mn(hm);
        }
        }
    } else
    {
        rabota_s_mn(hm);
    }
return 0;
}

