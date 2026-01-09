/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmounci <asmounci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:09:31 by asmounci          #+#    #+#             */
/*   Updated: 2026/01/08 18:05:30 by asmounci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next_node;
}	t_node;

typedef struct s_cost
{
	int	cost_b;
	int	cost_a;
	int	total;
	int	target_idx;
	int	dir_a;
	int	dir_b;
}	t_cost;

typedef struct s_cheapest_ctx
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
}	t_cheapest_ctx;

long	ft_atoi_long(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t	count_words(char const *s, char c);
size_t	word_length(char const *s, char c);
void	free_array(char **array, size_t index);
char	**extract_words(char **array, const char *s, char c);

int		has_duplicate(t_node *head, int value);
int		validate_argument(char *str);
int		create_node_and_add(t_node **stack_a, char *arg);
int		process_arguments(t_node **stack_a, char **args, int start);
int		process_multiple_args(t_node **stack_a, char **av, int ac);

t_node	*new_node(int val);
void	add_back(t_node **head, t_node *n_node);
void	swap_nodes(t_node **head);
void	rotate(t_node **head);
void	reverse_rotate(t_node **head);
void	free_nodes(t_node **head);

void	sa(t_node **head);
void	sb(t_node **head);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **head);
void	rb(t_node **head);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **head);
void	rrb(t_node **head);
void	rrr(t_node **stack_a, t_node **stack_b);

int		is_sorted(t_node *head);
int		count_nodes(t_node *head);
int		find_min_index(t_node *head);
void	rotate_to_pos(t_node **stack, int position, int size, char stack_n);

void	sort_2(t_node **head);
void	sort_3(t_node **head);
void	sort_5(t_node **stack_a, t_node **stack_b);

void	sort_large(t_node **stack_a, t_node **stack_b);
int		find_target_index(t_node *stack_a, int value_b);
int		get_cost(int index, int size);
int		calc_total_cost(int idx_b, int idx_a, int size_b, int size_a);
void	rotate_both(t_node **stack_a, t_node **stack_b, t_cost *cost, int dir);
void	bubble_sort_array(int *arr, int size);
int		find_cheapest_move(t_cheapest_ctx ctx, t_cost *best);
void	do_rotate(t_node **stack_a, t_node **stack_b, t_cost *cost);
void	execute_cheapest_move(t_node **stack_a, t_node **stack_b,
			int size_a, int size_b);
int		get_median_value(t_node *stack, int size);
void	final_rotation(t_node **stack_a);

#endif