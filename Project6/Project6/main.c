#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generatePassword(int minLength, int maxLength, int length, int count, char* alphabet) 
{
    srand(time(NULL));
    int i, j;
    for (i = 0; i < count; i++) 
    {
        int passwordLength = (length != 0) ? length : (rand() % (maxLength - minLength + 1)) + minLength;
        char* password = (char*)malloc((passwordLength + 1) * sizeof(char));

        for (j = 0; j < passwordLength; j++) 
        {
            int index = rand() % strlen(alphabet);
            password[j] = alphabet[index];
        }

        password[passwordLength] = '\0';
        printf("%s\n", password);

        free(password);
    }
}

int main(int argc, char* argv[]) 
{
    int minLength = 0;
    int maxLength = 0;
    int length = 0;
    int count = 1;
    const char* alphabet = NULL;
    const char* charSet = NULL;

    int i;
    int aFlag = 0;
    int m1Flag = 0;
    int m2Flag = 0;
    int nFlag = 0;
    int cFlag = 0;
    int CFlag = 0;
    for (i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-m1") == 0) 
        {
            if (m1Flag == 0) 
            {
                if (i + 1 != argc) 
                {
                    minLength = atoi(argv[i + 1]);
                    i++;
                }
                else 
                {
                    printf("No argument -m1\n");
                    return 1;
                }
            }
            else
            {
                printf("-m1 was used\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-m2") == 0) 
        {
            if (m2Flag == 0) 
            {
                if (i + 1 != argc) 
                {
                    maxLength = atoi(argv[i + 1]);
                    i++;
                }
                else 
                {
                    printf("No argument -m2\n");
                    return 1;
                }
            }
            else
            {
                printf("-m2 was used\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-n") == 0) 
        {
            if (nFlag == 0) 
            {
                if (i + 1 != argc) 
                {
                    length = atoi(argv[i + 1]);
                    i++;
                }
                else 
                {
                    printf("No argument -n\n");
                    return 1;
                }
            }
            else
            {
                printf("-n was used\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-c") == 0) 
        {
            if (cFlag == 0)
            {
                if (i + 1 != argc) 
                {
                    count = atoi(argv[i + 1]);
                    i++;
                }
                else 
                {
                    printf("No argument -c\n");
                    return 1;
                }
            }
            else
            {
                printf("-c was used\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-a") == 0)
        {
            if (aFlag == 0) 
            {
                if (i + 1 != argc) 
                {
                    alphabet = argv[i + 1];
                    i++;
                    aFlag = 1;
                    
                }
                else 
                {
                    printf("No argument -a\n");
                    return 1;
                }
            }
            else 
            {
                printf("-a was used");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-C") == 0) 
        {
            if (CFlag == 0) 
            {
                if (i + 1 != argc) 
                {
                    charSet = argv[i + 1];
                    i++;
                    CFlag = 1;
                }
                else 
                {
                    printf("No argument -C\n");
                    return 1;
                }
            } 
            else
            {
                printf("-C was used\n");
                return 1;
            }
        }
    }

    if ((minLength != 0 || maxLength != 0) && length != 0) 
    {
        printf("Arguments -m1, -m2, and -n can't stand together\n");
        return 1;
    }

    if (alphabet != NULL && charSet != NULL) 
    {
        printf("Arguments -a and -C can't stand together\n");
        return 1;
    }

    if (charSet != NULL) 
    {
        if (strlen(charSet) > 4)
        {
            printf("Wrong charset\n");
            return 1;
        }
        char* lowercase = "abcdefghijklmnopqrstuvwxyz";
        char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char* digits = "0123456789";
        char* symbols = "!@#$%^&*()\'\\";

        int lowercaseFlag = 0;
        int uppercaseFlag = 0;
        int digitsFlag = 0;
        int symbolsFlag = 0;

        for (i = 0; i < strlen(charSet); i++) 
        {
            switch (charSet[i]) 
            {
            case 'a':
                if (lowercaseFlag)
                {
                    printf("Wrong charset\n");
                    return 1;
                }
                lowercaseFlag = 1;
                break;
            case 'A':
                if (uppercaseFlag)
                {
                    printf("Wrong charset\n");
                    return 1;
                }
                uppercaseFlag = 1;
                break;
            case 'D':
                if (digitsFlag)
                {
                    printf("Wrong charset\n");
                    return 1;
                }
                digitsFlag = 1;
                break;
            case 'S':
                if (symbolsFlag)
                {
                    printf("Wrong charset\n");
                    return 1;
                }
                symbolsFlag = 1;
                break;
            default:
                printf("Extra arguments in -C\n");
                return 1;
            }
        }

        int charSetLength = lowercaseFlag * strlen(lowercase) + uppercaseFlag * strlen(uppercase) + digitsFlag * strlen(digits) + symbolsFlag * strlen(symbols) + 1;

        char* fullCharSet = (char*)malloc((charSetLength + 1) * sizeof(char));
        int index = 0;

        if (lowercaseFlag) 
        {
            strcpy(fullCharSet + index, lowercase);
            index += strlen(lowercase);
        }

        if (uppercaseFlag) 
        {
            strcpy(fullCharSet + index, uppercase);
            index += strlen(uppercase);
        }

        if (digitsFlag) 
        {
            strcpy(fullCharSet + index, digits);
            index += strlen(digits);
        }

        if (symbolsFlag) 
        {
            strcpy(fullCharSet + index, symbols);
            index += strlen(symbols);
        }

        fullCharSet[charSetLength] = '\0';

        generatePassword(minLength, maxLength, length, count, fullCharSet);

        free(fullCharSet);
    }
    else if (alphabet != NULL) 
    {
        generatePassword(minLength, maxLength, length, count, alphabet);
    }
    else 
    {
        printf("No used -a or -C\n");
        return 1;
    }
    return 0;
}
