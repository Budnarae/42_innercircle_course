/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:14:17 by sihong            #+#    #+#             */
/*   Updated: 2023/10/18 13:14:19 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * 버퍼에서 <이번 get_next_line에서의 버퍼 시작 지점> <개행이나 null을 만난 지점> 사이를 substr로 잘라 반환
*/

int	read_line(t_list *head, char **result, size_t i, int fd)
{
	int	func_returned;

	func_returned = read(fd, &head->buf[i], BUFFER_SIZE);
	if (func_returned == 0)
	{
		head->is_end = 1;
		if (head->store != i)
		{
			*result = ft_substr(head->buf, head->store, i + 1 - head->store, 0);
			if (*result == 0)
				return (0);
			return (1);
		}
		else
			return (0);
	}
	if (func_returned == -1)
	{
		head->is_end = 1;
		return (0);
	}
	return (-1);
}

/*
 * 개행을 못 만다고 다시 read헤서 버퍼를 이어붙일 때, 버퍼의 공간이 모자라면 버퍼 크기를 2배로 하여 재할당
*/

int	change_buf_size(size_t *buf_size, size_t *i, t_list *head)
{
	char	*buf_temp;

	if (*i + BUFFER_SIZE >= *buf_size)
	{
		if (*i + BUFFER_SIZE >= *buf_size)
			*buf_size *= 2;
		buf_temp = head->buf;
		head->buf = ft_substr(buf_temp, head->store, *buf_size, *buf_size);
		free(buf_temp);
		if (head->buf == 0)
		{
			head->is_end = 1;
			return (0);
		}
	}
	return (1);
}

/*
 * 개행이나 null을 만날때까지 버퍼 조회
 * 만나면 substr로 잘라서 반환
*/

int	end_with_nl(t_list *head, size_t buf_size, size_t *i, char **result)
{
	while (head->buf[*i] != '\n' && head->buf[*i] != 0 && *i < buf_size)
		(*i)++;
	if (*i < buf_size && head->buf[*i] == '\n')
	{
		*result = ft_substr(head->buf, head->store, *i + 1 - head->store, 0);
		if (*result == 0)
		{
			head->is_end = 1;
			return (0);
		}
		head->store = *i + 1;
		return (1);
	}
	return (-1);
}

/*
 * 버퍼 사이즈를 처음부터 크게 지정하는 이유는 giant_line 같은 케이스에서 time out이 나는 것을 방지하기 위해서.
 * 저번 호출에서 store에 저장된 값이 buffer_size를 초과하면 다시 버퍼 사이즈 키워줌.
 * 입력된 fd에 맞는 노드로 이동
*/

int	set_data(size_t *buf_size, size_t *i, t_list **head, int fd)
{
	*buf_size = 4096;
	*i = 1;
	while (*buf_size * *i < BUFFER_SIZE)
		(*i)++;
	*buf_size = *buf_size * *i;
	while ((*head)->fd != fd)
		*head = (*head)->next;
	while ((*head)->store + BUFFER_SIZE >= *buf_size)
		*buf_size *= 2;
	if ((*head)->buf == 0)
	{
		(*head)->buf = ft_calloc(*buf_size, sizeof(char));
		if ((*head)->buf == 0)
		{
			(*head)->is_end = 1;
			return (0);
		}
		if (read(fd, (*head)->buf, BUFFER_SIZE) <= 0)
		{
			(*head)->is_end = 1;
			return (0);
		}
	}
	*i = (*head)->store;
	return (1);
}

/*
 * 저번에 읽은 지점 ~ 개행 또는 null로 끝나는 지점까지 복사해 반환하고, 다음에 read할 때를 위해 buffer의 어디까지 읽었는지 노드의 store에 저장
*/

char	*read_file(t_list *head, int fd)
{
	size_t	buf_size;
	size_t	i;
	int		func_returned;
	char	*result;

	if (set_data(&buf_size, &i, &head, fd) == 0)
		return (0);
	while (1)
	{
		func_returned = end_with_nl(head, buf_size, &i, &result);
		if (func_returned == 0)
			return (0);
		else if (func_returned == 1)
			return (result);
		if (i >= buf_size || (i < buf_size && head->buf[i] == 0))
		{
			if (change_buf_size(&buf_size, &i, head) == 0)
				return (0);
			func_returned = read_line(head, &result, i, fd);
			if (func_returned == 0)
				return (0);
			else if (func_returned == 1)
				return (result);
		}
	}
}
