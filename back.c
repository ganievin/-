#include <stdio.h>

void rabota_s_mn(int b) {
        int counter0=0; //�������
        int pos_or_neg = 1; //���������� ���� ������� ��-��
        long long int d_set[b]; //���������� ����������� ��������� � ������ b
        int b_set[b][sizeof(int)*8]; //���������� ��������� ����������� ��������� � ������ b, ������ ������� ��� �� ����� ����� ���������� ��� �������������� ����
        for (counter0;counter0<b;counter0++)
        {
            d_set[counter0] = 0;
            printf("������� %d-� ������� ��������� (<10000): ", counter0+1);

            while (d_set[counter0] == 0 || d_set[counter0] >= 10000) {
                d_set[counter0] = check_num();
                if (d_set[counter0] >= 10000){
                    printf("������ �����");
                }
            }
            if (d_set[counter0]<0){
                pos_or_neg = 0;
                d_set[counter0] = 0-d_set[counter0];
            }


            int ost; //���������� ��� �������� �������� � ������ �������� �����
            int current_number = d_set[counter0]; //���������� ��� �������� ��-��, ������� ���� ������������, ����� - ������ �� �������


            int counter1=0; //������� ������������ �����
            while (counter1 != 32)
            {
                ost = current_number%2;
                current_number = current_number/2;

                int lbst_elem_num = sizeof(int)*8-1;
                int reversed_lbst_elem_num = lbst_elem_num-counter1;


                b_set[counter0][reversed_lbst_elem_num] = ost;
                counter1++;
            } //���� ��� �������� �������� �������� � �������� ��� ��� ��������� ���������
        }













        int counter2 = 0;
        for (counter2;counter2<b;counter2++)
        {
            printf("%d-� ������� ����������� ��������� %d\n", counter2+1, d_set[counter2]); //����� counter2-�� �������� ����������� ���������

            int counter3 = 0;
            int indicbtor = 0;
            printf("��������������� ��� ������� ��������� ��������� ", counter2+1); //����� counter2-�� �������� ��������� ���������
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
            }//���� ��� ����������������� ������ �������� ����� ��� ������� �������� ��������� ���������

            printf("\n\n");

        }//���� ��� ����������������� ������ �������� ��� ������� �������� ����������� � ��������� ��������

}



void arifm_prog_mn(int b) {
            printf("\n���� �������� ������ �������������� ����������: ");

            int counter4=0; //�������
            int x; //�������� ����������
            int first_var = -1; //��������� ��-� ���������

            int d_set[b]; //���������� ����������� ��������� � ������ b
            int b_set[b][sizeof(int)*8]; //���������� ��������� ����������� ��������� � ������ b, ������ ������� ��� �� ����� ����� ���������� ��� �������������� ����
            int pos_or_neg = 1; //���������� ���� ������� ��-��

            printf("\n������� 1-� ������� ��������� 1000 > x >= 0: ");

            while (first_var <= 0 || first_var > 1000) {
                first_var = check_num();
                if (first_var <= 0 || first_var > 1000){
                    printf("������ �����");
                }
            }

            printf("\n������� �������� �������������� ���������� (������������� ��� 0): ");
            scanf("%d", &x);

            for (counter4;counter4<b;counter4++)
            {
                if (counter4 !=0){
                    d_set[counter4] = d_set[counter4 - 1] + x;
                } else {
                    d_set[counter4] = first_var;
                }

                int ost; //���������� ��� �������� �������� � ������ �������� �����
                int current_number = d_set[counter4]; //���������� ��� �������� ��-��, ������� ���� ������������, ����� - ������ �� �������
                int counter5=0; //������� ������������ �����
                while (counter5 != 32)
                {
                    ost = current_number%2;
                    current_number = current_number/2;

                    int lbst_elem_num = sizeof(int)*8-1;
                    int reversed_lbst_elem_num = lbst_elem_num-counter5;


                    b_set[counter4][reversed_lbst_elem_num] = ost;
                    counter5++;

                } //���� ��� �������� �������� �������� � �������� ��� ��� ��������� ���������
            }












            int counter2 = 0;
            for (counter2;counter2<b;counter2++)
            {
                printf("%d-� ������� ����������� ��������� %d\n", counter2+1, d_set[counter2]); //����� counter2-�� �������� ����������� ���������

                int counter3 = 0;
                int indicbtor = 0;
                printf("��������������� ��� ������� ��������� ��������� ", counter2+1); //����� counter2-�� �������� ��������� ��������

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

                //���� ��� ����������������� ������ �������� ����� ��� ������� �������� ��������� ���������

                printf("\n\n");

            }//���� ��� ����������������� ������ �������� ��� ������� �������� ����������� � ��������� ��������
}

int check_num(){
    int c, choose;
    int error = 0;
    scanf("%d", &choose);

    // ������ ����� ����� � ���������, ��� ����� ����� ��� ������ ��������.
    // ������� ��������� ��� ������� �� ����� ������.
    while ((c = getchar()) != '\n' && c != EOF) {
        // ���� ������ �� �������� �������� ��� ����������, �������,
        // ��� ������� ������ �������.
        if (c != ' ' && c != '\t') {
            error = 1;
        }
    }

    if (error) {
        printf("������ �����.\n");
        return 0;
    } else {
        return choose;
    }

}





