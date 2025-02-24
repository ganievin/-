#include <stdio.h>

void rabota_s_mn(int b) {
        int counter0=0; //счетчик
        int pos_or_neg = 1; //определяем знак каждого эл-та
        long long int d_set[b]; //объявление десятичного множества с длиной b
        int b_set[b][sizeof(int)*8]; //объявление двоичного двухмерного множества с длиной b, каждый элемент его по длине равен количеству бит целочисленного типа
        for (counter0;counter0<b;counter0++)
        {
            d_set[counter0] = 0;
            printf("Введите %d-й элемент множества (<10000): ", counter0+1);

            while (d_set[counter0] == 0 || d_set[counter0] >= 10000) {
                d_set[counter0] = check_num();
                if (d_set[counter0] >= 10000){
                    printf("Ошибка ввода");
                }
            }
            if (d_set[counter0]<0){
                pos_or_neg = 0;
                d_set[counter0] = 0-d_set[counter0];
            }


            int ost; //переменная для хранения остатков в каждой итерации цикла
            int current_number = d_set[counter0]; //переменная для хранения эл-та, который ввел пользователь, затем - целого от деления


            int counter1=0; //счетчик последующего цикла
            while (counter1 != 32)
            {
                ost = current_number%2;
                current_number = current_number/2;

                int lbst_elem_num = sizeof(int)*8-1;
                int reversed_lbst_elem_num = lbst_elem_num-counter1;


                b_set[counter0][reversed_lbst_elem_num] = ost;
                counter1++;
            } //цикл для перевода текущего элемента в двоичный вид для бинарного множества
        }













        int counter2 = 0;
        for (counter2;counter2<b;counter2++)
        {
            printf("%d-й элемент десятичного множества %d\n", counter2+1, d_set[counter2]); //вывод counter2-го элемента десятичного множества

            int counter3 = 0;
            int indicbtor = 0;
            printf("соответствующий ему элемент бинарного множества ", counter2+1); //вывод counter2-го элемента бинарного множества
            if (pos_or_neg == 0)
            {
                printf("-");
            }
            for (counter3;counter3<sizeof(int)*8;counter3++)
            {
                if (indicbtor == 1 || b_set[counter2][counter3] == 1)
                {
                    printf("%d", b_set[counter2][counter3]);
                    indicbtor = 1;
                } else if (counter3 == 31 && indicbtor ==0 && b_set[counter2][counter3] == 0)
                {
                    printf("0");
                }
            }//цикл для последовательного вывода значения битов для каждого элемента бинарного множества

            printf("\n\n");

        }//цикл для последовательного вывода значения для каждого элемента десятичного и бинарного множеств

}



void arifm_prog_mn(int b) {
            printf("\nПока доступна только арифметическая прогрессия: ");

            int counter4=0; //счетчик
            int x; //разность прогрессии
            int first_var = -1; //начальный эл-т прогресии

            int d_set[b]; //объявление десятичного множества с длиной b
            int b_set[b][sizeof(int)*8]; //объявление двоичного двухмерного множества с длиной b, каждый элемент его по длине равен количеству бит целочисленного типа
            int pos_or_neg = 1; //определяем знак каждого эл-та

            printf("\nВведите 1-й элемент множества 1000 > x >= 0: ");

            while (first_var <= 0 || first_var > 1000) {
                first_var = check_num();
                if (first_var <= 0 || first_var > 1000){
                    printf("Ошибка ввода");
                }
            }

            printf("\nВведите разность арифметической прогрессии (положительный или 0): ");
            scanf("%d", &x);

            for (counter4;counter4<b;counter4++)
            {
                if (counter4 !=0){
                    d_set[counter4] = d_set[counter4 - 1] + x;
                } else {
                    d_set[counter4] = first_var;
                }

                int ost; //переменная для хранения остатков в каждой итерации цикла
                int current_number = d_set[counter4]; //переменная для хранения эл-та, который ввел пользователь, затем - целого от деления
                int counter5=0; //счетчик последующего цикла
                while (counter5 != 32)
                {
                    ost = current_number%2;
                    current_number = current_number/2;

                    int lbst_elem_num = sizeof(int)*8-1;
                    int reversed_lbst_elem_num = lbst_elem_num-counter5;


                    b_set[counter4][reversed_lbst_elem_num] = ost;
                    counter5++;

                } //цикл для перевода текущего элемента в двоичный вид для бинарного множества
            }












            int counter2 = 0;
            for (counter2;counter2<b;counter2++)
            {
                printf("%d-й элемент десятичного множества %d\n", counter2+1, d_set[counter2]); //вывод counter2-го элемента десятичного множества

                int counter3 = 0;
                int indicbtor = 0;
                printf("соответствующий ему элемент бинарного множества ", counter2+1); //вывод counter2-го элемента бинарного множеств

                for (counter3;counter3<sizeof(int)*8;counter3++)
                {
                    if (indicbtor == 1 || b_set[counter2][counter3] == 1)
                    {
                            printf("%d", b_set[counter2][counter3]);
                            indicbtor = 1;
                    } else if (counter3 == 31 && indicbtor == 0 && b_set[counter2][counter3] == 0)
                    {
                            printf("0");
                    }
                }

                //цикл для последовательного вывода значения битов для каждого элемента бинарного множества

                printf("\n\n");

            }//цикл для последовательного вывода значения для каждого элемента десятичного и бинарного множеств
}

int check_num(){
    int c, choose;
    int error = 0;
    scanf("%d", &choose);

    // Чистим буфер ввода — проверяем, что после числа нет лишних символов.
    // Сначала считываем все символы до конца строки.
    while ((c = getchar()) != '\n' && c != EOF) {
        // Если символ не является пробелом или табуляцией, считаем,
        // что введены лишние символы.
        if (c != ' ' && c != '\t') {
            error = 1;
        }
    }

    if (error) {
        printf("Ошибка ввода.\n");
        return 0;
    } else {
        return choose;
    }

}





