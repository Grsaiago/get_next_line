/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:00:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/27 20:01:49 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

struct aluno
{
	int		nota;
	char	*nome;
	struct	aluno *next;
};


void	printnotas(struct aluno *begin)
{
	if (!begin)
		return ;
	while (begin)
	{
		printf("nota do aluno %s > %d\n", begin->nome, begin->nota);
		begin = begin->next;
	}
}

int	main(void)
{
	struct aluno	aluno1;
	struct aluno	aluno2;
	struct aluno	aluno3;
	struct aluno	aluno4;
	struct aluno	*begin;

//atribuições.
	begin = &aluno1;
	aluno1.next = &aluno2;
	aluno2.next = &aluno3;
	aluno3.next = &aluno4;
	aluno4.next = 0;
//notas.
	aluno1.nota = 8;
	aluno2.nota = 5;
	aluno3.nota = 7;
	aluno4.nota = 9;
//iniciais
	aluno1.nome = "Gabriel";
	aluno2.nome = "João";
	aluno3.nome = "Pedro";
	aluno4.nome = "Filipe";
//
	printnotas(begin);
}
