#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)
using namespace std;

int question_number = 1;      //��Ŀ����,Ĭ��Ϊ1
int symbol_number = 1;        //�����������,Ĭ��Ϊ1
char symbol_type[5] = { 0 };    //��������࣬Ĭ��Ϊ��
int max_number = 1;           //�������Ĭ��Ϊ1
int brackets = 0;             //�Ƿ������ţ�1��ʾ�����ţ�0��ʾû�����ţ�,Ĭ��Ϊ0
int decimal = 0;              //�Ƿ���С����1��ʾ��С����0��ʾû��С����,Ĭ��Ϊ0
int print_style = 0;          //�û�ѡ�������ʽ��1��ʾ������ļ���0��ʾ�����Ļ��,Ĭ��Ϊ0
float number[5] = { 0 };        //ʹ�õ�����,Ĭ��Ϊ0
char symbol[4] = { 0 };         //ʹ�õ��������Ĭ��Ϊ��

void menu(void)//���˵�����
{
    printf("*************************************************************************\n");
    printf("                       ��������ϰ���Զ�������                            \n");
    printf("\n");
    printf("                       �밴��ʾ������ϰ������                            \n");
    printf("*************************************************************************\n");
}

void parameter(void)//��������
{
    printf("��������Ŀ��������������\n");
    scanf("%d", &question_number);
    if (question_number <= 0)
    {
        printf("������������Ŀ��������������\n");
        scanf("%d", &question_number);
    }
    printf("�����������������(1~4֮�������)\n");
    scanf("%d", &symbol_number);
    if ((symbol_number < 1) || (symbol_number > 4))
    {
        printf("���������������������(1~4֮�������)\n");
        scanf("%d", &symbol_number);
    }
    printf("����������ʹ�õ���������ڡ�+������-������*������/����ѡ�����룬�����������룩\n");
    scanf("%s", symbol_type);
    printf("���������������������\n");
    scanf("%d", &max_number);
    if (max_number <= 0)
    {
        printf("�������������������������\n");
        scanf("%d", &max_number);
    }
    printf("��ѡ���Ƿ������ţ�0��ʾû�����ţ��������ֱ�ʾ�����ţ�\n");
    scanf("%d", &brackets);
    printf("��ѡ���Ƿ���С����0��ʾû��С�����������ֱ�ʾ��С����\n");
    scanf("%d", &decimal);
    printf("��ѡ�������ʽ��0��ʾ�������Ļ���������ֱ�ʾ������ļ���\n");
    scanf("%d", &print_style);
}

void randomnumber(void)//�����������
{
    for (int i = 0; i < 4; i++)
    {
        if (decimal == 0)//�����������
        {
            number[i] = rand() % (max_number + 1);
        }
        else//�������С��
        {
            number[i] = rand() % max_number;
            number[i] = number[i] + rand() % 100 * 0.01;
        }
    }
}

void randomsymbol(void)//�����������
{
    for (int i = 0; i < 3; i++)
    {
        symbol[i] = symbol_type[rand() % symbol_number];
    }
}

void print_expression(void)//�������
{
    int brackets_place;   //����λ��
    FILE* fp;             //�ļ�ָ��
    fp = fopen("Four operational exercises.txt", "w");//���ļ�д����
    for (int m = 0; m < question_number; m++)
    {
        randomnumber();//�����������
        randomsymbol();//�����������
        for (int i = 0; i < 3; i++)
        {
            if ((symbol[i] == '/') && (number[i + 1] == 0))//����Ϊ0ʱ��������Ϊ�������ִ���ѳ�����һ
            {
                number[i + 1] = number[i + 1] + 1;
            }
        }
        if (decimal == 0)//����С��
        {
            if (print_style == 0)//�������Ļ
            {
                if (brackets == 0)//û������
                {
                    printf("%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                }
                else//������
                {
                    brackets_place = rand() % 3;
                    if (brackets_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        printf("��%.0f%c%.0f��%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 1)//�����ڵڶ������͵���������
                    {
                        printf("%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 2)//�����ڵ��������͵��ĸ�����
                    {
                        printf("%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                }
            }
            else//������ļ�
            {
                if (brackets == 0)//û������
                {
                    fprintf(fp, "%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                }
                else//������
                {
                    brackets_place = rand() % 3;
                    if (brackets_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        fprintf(fp, "��%.0f%c%.0f��%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 1)//�����ڵڶ������͵���������
                    {
                        fprintf(fp, "%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 2)//�����ڵ��������͵��ĸ�����
                    {
                        fprintf(fp, "%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                }
            }
        }
        else//��С��
        {
            if (print_style == 0)//�������Ļ
            {
                if (brackets == 0)//û������
                {
                    printf("%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                }
                else//������
                {
                    brackets_place = rand() % 3;
                    if (brackets_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        printf("��%.2f%c%.2f��%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 1)//�����ڵڶ������͵���������
                    {
                        printf("%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 2)//�����ڵ��������͵��ĸ�����
                    {
                        printf("%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                }
            }
            else//������ļ�
            {
                if (brackets == 0)//û������
                {
                    fprintf(fp, "%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                }
                else//������
                {
                    brackets_place = rand() % 3;
                    if (brackets_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        fprintf(fp, "��%.2f%c%.2f��%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 1)//�����ڵڶ������͵���������
                    {
                        fprintf(fp, "%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                    if (brackets_place == 2)//�����ڵ��������͵��ĸ�����
                    {
                        fprintf(fp, "%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
                    }
                }
            }
        }
    }
    fclose(fp);//�ر��ļ�
}

int main()
{
    menu();              //���˵�����
    parameter();         //��������
    srand((int)time(0)); //��֤ÿ�β������������ͬ
    print_expression();  //�������
    return 0;
}