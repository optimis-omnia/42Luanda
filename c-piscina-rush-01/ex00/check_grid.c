/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:22:14 by epinto            #+#    #+#             */
/*   Updated: 2023/11/26 19:22:36 by epinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);

// direcao vertical: UP-DOWN
int	check_ver_down(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 0;
	max = 0;
	c_changes = 0;
	while (i < 4)
	{
		if (matrix[i][clue_ind] > max)
		{	
			c_changes++;
			max = matrix[i][clue_ind];
		}
		i++;
	}
	return (c_changes == clues[clue_ind]);
}

// direcao vertical: DOWN-UP
int	check_ver_up(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 3;
	max = 0;
	c_changes = 0;
	while (i > -1)
	{
		if (matrix[i][clue_ind - 4] > max)
		{	
			c_changes++;
			max = matrix[i][clue_ind - 4];
		}
		i--;
	}
	max = 0;
	return (c_changes == clues[clue_ind]);
}

//direcao horizontal
int	check_hor_right(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 0;
	max = 0;
	c_changes = 0;
	while (i < 4)
	{
		if (matrix[clue_ind - 8][i] > max)
		{	
			max = matrix[clue_ind - 8][i];
			c_changes++;
		}
		i++;
	}
	return (c_changes == clues[clue_ind]);
}

//direcao horizontal
int	check_hor_left(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 3;
	max = 0;
	c_changes = 0;
	while (i > -1)
	{
		if (matrix[clue_ind - 12][i] > max)
		{
			max = matrix[clue_ind - 12][i];
			c_changes++;
		}
		i--;
	}
	return (c_changes == clues[clue_ind]);
}

int	check_entire_matrix(int matrix[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i <= 15)
	{	
		if (i >= 0 && i <= 3 && !(check_ver_down(matrix, clues, i)))
		{
			return (0);
		}
		if (i >= 4 && i <= 7 && !(check_ver_up(matrix, clues, i)))
		{
			return (0);
		}
		if (i >= 8 && i <= 11 && !(check_hor_right(matrix, clues, i)))
		{	
			return (0);
		}
		if (i >= 12 && i <= 15 && !(check_hor_left(matrix, clues, i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
