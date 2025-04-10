#include "../../includes/philo.h"

int ft_strlen(const char *s)
{
    int cnt;

    cnt = 0;
    while (s[cnt++])
        ;
    return (cnt);
}
