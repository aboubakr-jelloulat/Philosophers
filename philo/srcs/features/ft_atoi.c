#include "../../includes/philo.h"

static int  is_space(int c)
{
    return (c == ' ' || c == '\t' || c == '\v' ||c == '\r' || c == '\f' || c == '\n');
}

static int  is_digit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
    int res;
    int sign;
    int i;

    i = 0;
    res = 0;
    sign = 1;
    while (is_space(str[i]))
        i++;
    if (str[i] == '-')
        return (-42);
    if (str[i] == '+')
        i++;
    while (str[i])
    {
        if (is_digit(str[i]))
            res = (res * 10) + str[i++] - 48;
        else
            return (-42);
    }
    return (res * sign);
}
