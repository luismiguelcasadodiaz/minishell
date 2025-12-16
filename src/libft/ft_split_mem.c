/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:23:39 by luicasad          #+#    #+#             */
/*   Updated: 2024/03/08 10:32:41 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* ************************************************************************** */
/* Allocate(), allocates memory for a table of 'num' pointers to char. Also   */
/* allocates one more pointer settled to ((void *)0).                         */
/*                                                                            */
/* GETS                                                                       */
/*  rows : the amount of rows we want the table to hold                       */
/*                                                                            */
/* RETURNS                                                                    */
/*  table : a pointer to the first row of the created table having last row   */
/*          Setttled to NULL                                                  */
/*                                                                            */
/* ************************************************************************** */
char	**allocate(size_t rows)
{
	char	**table;

	table = (char **)malloc((rows + 1) * sizeof (char *));
	if (table == NULL)
		return (NULL);
	table[rows] = ((void *)0);
	return (table);
}

/* ************************************************************************** */
/* de_allocate(), frees memory holding a table of pointers                    */
/*                                                                            */
/* GETS                                                                       */
/*  table : the pointer to the table to release memory from                   */
/*  rows : the amount of rows already allocated into the table.               */
/*                                                                            */
/* RETURNS                                                                    */
/*  NULL, once all memory was released.                                       */
/*                                                                            */
/* OPERATES                                                                   */
/*  Loops table's from last one allocated row (--rows) releasing the          */
/*  memory for each row. Use pre-decrement cause 4 rows allocated are indexed */
/*  from 3, 2, 1, 0. LUIS REMEMBER THAT!!!!!!                                 */
/*                                                                            */
/*  Finally release the pointer to the table itself                           */
/*                                                                            */
/*   NOTE: not necessary release table[rows] = ((void *)0) settled inside     */
/*         allocate. was not a pointer to a word allocated memory             */
/* ************************************************************************** */
char	**de_allocate(char **table, size_t allocated_rows)
{
	while (allocated_rows > 0)
	{
		free(table[--allocated_rows]);
	}
	free(table);
	return (NULL);
}
