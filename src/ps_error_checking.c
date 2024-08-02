/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:02:19 by jnenczak          #+#    #+#             */
/*   Updated: 2024/08/02 17:59:56 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long ps_strtol(const char *str, char **endptr)
{
    long	result;
    int		sign;

	result = 0;
	sign = 1;
    while (*str == ' ' || *str == '\t')
		str++;
    if (*str == '-' || *str == '+')
    {
		if (*str == '-')
			sign = -1;
		str++;
	}
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (endptr)
		*endptr = (char*)str;
    return (sign * result);
}

int	ps_is_valid_integer(const char *str)
{
    char	*endptr;
    long	val;

	if (*str == '\0')
		return (0);
	val = ps_strtol(str, &endptr);
    return (*endptr == '\0' && val >= INT_MIN && val <= INT_MAX);
}

int ps_has_duplicates(t_stack *stack)
{
    t_node *current = stack->top;
    while (current) {
        t_node *check = current->next;
        while (check) {
            if (current->value == check->value) {
                return 1;
            }
            check = check->next;
        }
        current = current->next;
    }
    return 0;
}