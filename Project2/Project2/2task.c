#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* x, char* y) {
    char t = *x; *x = *y; *y = t;
}

char* reverse(char* buffer, int i, int j)
{
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }

    return buffer;
}

// ����������� ������� ��� ���������� ������� `itoa()` � C
char* itoaa(int value, char* buffer, int base)
{
    // ������������ ����
    if (base < 2 || base > 32) {
        return buffer;
    }

    // ������� ���������� �������� �����
    int n = abs(value);

    int i = 0;
    while (n)
    {
        int r = n % base;

        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }

        n = n / base;
    }

    // ���� ����� ����� 0
    if (i == 0) {
        buffer[i++] = '0';
    }

    // ���� ��������� ����� 10 � �������� �������������, �������������� ������
    // ������������ ���� ����� (-)
    // ��� ����� ������ ���� �������� ������ ��������� �����������
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0'; // ������� ����������� ������

    // �������������� ������ � ���������� ��
    return reverse(buffer, 0, i - 1);
}
int DigitsCounter(int n) {
    int counter = 0;
    while (n != 0) {
        n = n / 10;
        counter++;
    }
    return counter;//������� ���������� ������� ���� �� ������ = 0
}
int main()
{
    int N;
    scanf_s("%d", &N);
    char* str = (char*)malloc((DigitsCounter(N) + 1) * sizeof(char));
    str = itoaa(N, str, 10);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] > str[i + 1])
        {
            if (!(str[i + 1] == '0' && i == 0) && str[i + 1] != '\0')
            {
                char tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
            }
        }
    }
    if (!(N == atoi(str)))
    {
        printf_s("%s\n", str);
        free(str);
    }
    else
    {
        printf_s("0\n");
        free(str);
    }
    return 0;
}