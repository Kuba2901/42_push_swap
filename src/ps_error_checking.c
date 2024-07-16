/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:02:19 by jnenczak          #+#    #+#             */
/*   Updated: 2024/07/16 15:22:57 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_is_valid_integer(const char *str)
{
    char *endptr;
    long val = strtol(str, &endptr, 10);
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