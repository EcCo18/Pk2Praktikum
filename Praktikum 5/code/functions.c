#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int countspace(char s[])
{
    int counter = 0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i] == ' ')
        {
            counter++;
        }
    }
    return counter;
}

double min(double a[], int n)
{
    double min = 0.0;
    
    for(int i=0; i<n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

char *stringcat(const char *str1, const char *str2)
{
    char *con_string = (char *)malloc((strlen(str1) + strlen(str2)) * sizeof(char));
    printf("str size: %lu\n", sizeof(con_string));

    char *ret = con_string;

    int str_len = strlen(str1);
    for(int i=0; i<str_len; i++)
    {
        *con_string = *str1;
        str1++;
        con_string++;
    }
    str_len = strlen(str2);
    for(int i=0; i<str_len; i++)
    {
        *con_string = *str2;
        str2++;
        con_string++;
    }
    return ret;
}

double fak(int number)
{
    if(number == 0)
    {
        return 1;
    }else
    {
        return number * fak(number-1);
    }
}

double binom(int n, int k)
{
    return (fak(n) / (fak(k) * (fak((n-k)))));
}