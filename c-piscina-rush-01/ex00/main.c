/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:23:15 by epinto            #+#    #+#             */
/*   Updated: 2023/11/26 19:23:23 by epinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	parse_and_put_to_array(int *arr, char *str_args);
int		is_valid_input(char *input);
int		solve(int matrix[4][4], int clues[16], int x, int y);

void	print_matrix(int size, int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putnbr(matrix[i][j]);
			if (j != (size - 1))
				ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

void	fill_empty_matrix(int size, int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{	
		while (j < size)
		{
			matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int	is_valid_buildg(int matrix[4][4], int buildg, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[y][i] == buildg || matrix[i][x] == buildg)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	matrix[4][4];
	int	*clues;

	clues = (int *) malloc(sizeof(int) * 16);
	if (argc != 2 || is_valid_input(argv[1]) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	parse_and_put_to_array(clues, argv[1]);
	fill_empty_matrix(4, matrix);
	if (solve(matrix, clues, 0, 0))
		print_matrix(4, matrix);
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
