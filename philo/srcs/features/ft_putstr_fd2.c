#include "../../includes/philo.h"

int ft_putstr_fd2(char *str_err)
{
    const char *style;
    const char *reset;

    style = RED BOLD;
    reset = RESET;
    write(2, style, ft_strlen(style));
    write(2, str_err, ft_strlen(str_err));
    write(2, reset, ft_strlen(reset));
    return (0);
}
