/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudakane <yudakane@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:44:28 by myazawa           #+#    #+#             */
/*   Updated: 2026/09/15 12:59:03 by yudakane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define ERROR_MS "Error\n"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
typedef struct s_stats
{
	bool			bench_enabled;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_stats;
int					ft_atoi(char *nptr, int *err);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
int					check_repeat(char **argv, int size, int start);
int					flag_search(char **argv, t_stack **a, t_stack **b,
						t_stats *sts);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int content, int i);
int					ft_strcmp(const char *s1, const char *s2);
int					free_stack(t_stack **stack);
t_stack				*a(char **argv, int n);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				sa(t_stack **a, t_stats *sts);
void				sb(t_stack **b, t_stats *sts);
void				ss(t_stack **a, t_stack **b, t_stats *sts);
void				pb(t_stack **a, t_stack **b, t_stats *sts);
void				pa(t_stack **a, t_stack **b, t_stats *sts);
t_stack				*ft_lstlast(t_stack *lst);
void				ra(t_stack **a, t_stats *sts);
void				rb(t_stack **b, t_stats *sts);
void				rr(t_stack **a, t_stack **b, t_stats *sts);
void				rra(t_stack **a, t_stats *sts);
void				rrb(t_stack **b, t_stats *sts);
void				rrr(t_stack **a, t_stack **b, t_stats *sts);
int					ft_lstsize(t_stack *lst);
int					decide_index(t_stack *a);
int					ft_sqrt(int nb);
int					is_almost_sorted(t_stack *a);
void				rotate_only(int i, t_stack **a, t_stats *sts);
void				selection_sort(t_stack **a, t_stack **b, t_stats *sts);
void				chunk_sort(t_stack **a, t_stack **b, t_stats *sts);
void				radix_sort(t_stack **a, t_stack **b, t_stats *sts);
void				print_bench(t_stats *sts, double dis, const char *strategy);
double				disorder(t_stack *a, int size, int *err);
void				adaptive_sort(t_stack **a, t_stack **b,
						t_stats *sts, int *err);
void				mini_3(t_stack **a, t_stats *sts);
void				mini_5(t_stack **a, t_stack **b, t_stats *sts);
char				**normalize_args(int argc, char **argv, int *real_argc);
char				**build_normalized(char *arg, int *real_argc);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, size_t start, size_t len);
#endif
