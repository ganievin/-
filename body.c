#include <stdio.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "Russian"); //��������� �����������

    int hm = 0;
    printf("����������, ������� ������������� ���������� ��������� � ��������� (�� 1 �� 1000): ");

    while (hm>1000 || hm<1) //��������� ������ ����� �������� ��������� � ���������� hm
    {
        hm = check_num();
    }


    if (hm>10)
    {
        printf("\n���������� ����� ���������!\n");
        printf("������ ������� ��� ��������� �� ������ ������-���� ������?\n");

        int choose1 = 0;

        while (choose1<1 || choose1>2)
        {
            printf("������� 1 ����� ��������� � ������\n");
            printf("������� 2 ����� ��������� �� ������\n");

            while (choose1 != 1 && choose1 != 2)
            {
                choose1 = check_num();
                if (choose1 != 1 && choose1 != 2) {
                    printf("�������� �����\n");
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

