#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#include <stdio.h>

#define BUFLEN 40000
#define	LEFT_ONE -1

typedef struct Client
{
	int		fd;
	int		buf_len;
	char	*buffer;
}	Client;

int fd_max = 0;
int	new_clnt_id = 0;
int	clnt_num = 1000;

Client	*clnt_lst = NULL;

typedef struct sockaddr_in sockaddr_in;

void	printFatalErrorExit()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}

int		ilen(int i)
{
	if (i < 0)
		printFatalErrorExit();
	if (i == 0)
		return (1);

	int	alen = 0;
	
	while (i != 0)
	{
		alen += 1;
		i /= 10;
	}

	return (alen);
}

char	*ft_substr(char *start, char *end)
{
	if (end < start)
		printFatalErrorExit();
	
	if (start == end)
		return (NULL);

	char	*str = calloc(end - start + 1, sizeof(char));
	if (str == NULL)
		printFatalErrorExit();
	
	for (int i = 0; i < end - start; i++)
		str[i] = start[i];
	
	return (str);
}

void	addNewFdToReadset(int fd, fd_set *set)
{
	FD_SET(fd, set);
	if (fd > fd_max)
		fd_max = fd;
}

void	removeFdFromReadsetAndClose(int fd, fd_set *set)
{
	FD_CLR(fd, set);
	close(fd);
}

void	sendMsgToAll(char *msg)
{
	for (int id = 0; id < clnt_num; id++)
	{
		if (clnt_lst[id].fd == 0)
			break ;
		if (clnt_lst[id].fd == LEFT_ONE)
			continue ;
		
		if (send(clnt_lst[id].fd, msg, strlen(msg), 0) == -1)
			printFatalErrorExit();
	}
}

void	sendNewClientMsgToAll()
{
	char	*new_clnt_msg = calloc(strlen("server: client ") + \
		ilen(new_clnt_id) + strlen(" just arrived\n") + 1, sizeof(char));
	if (new_clnt_msg == NULL)
		printFatalErrorExit();
	
	strcat(new_clnt_msg, "server: client ");
	sprintf(new_clnt_msg + strlen("server: client "), "%d", new_clnt_id);
	strcat(new_clnt_msg, " just arrived\n");

	sendMsgToAll(new_clnt_msg);

	free(new_clnt_msg);
}

void	sendClientLeftMsgToALL(int clnt_id)
{
	char	*clnt_left_msg = calloc(strlen("server: client ") + \
		ilen(clnt_id) + strlen(" just left\n") + 1, sizeof(char));
	if (clnt_left_msg == NULL)
		printFatalErrorExit();
					
	strcat(clnt_left_msg, "server: client ");
	sprintf(clnt_left_msg + strlen("server: client "), "%d", clnt_id);
	strcat(clnt_left_msg, " just left\n");

	sendMsgToAll(clnt_left_msg);

	free(clnt_left_msg);
}

void	addNewClientToArray(int clnt_fd)
{
	clnt_lst[new_clnt_id].fd = clnt_fd;
	new_clnt_id += 1;

	if (new_clnt_id == clnt_num)
	{
		clnt_num *= 2;

		Client	*tmp = clnt_lst;
		
		clnt_lst = calloc(clnt_num, sizeof(Client));
		if (clnt_lst == NULL)
			printFatalErrorExit();
		
		for (int id = 0; id < clnt_num / 2; id++)
			clnt_lst[id] = tmp[id];
		
		free(tmp);
	}
}

void	recordClientDisconnectionAtArray(Client *clnt)
{
	clnt->fd = LEFT_ONE;

	if (clnt->buffer)
	{
		free(clnt->buffer);
		clnt->buffer = NULL;
	}
}

int	findClientIdWithFd(int clnt_fd)
{
	for (int id = 0; id < clnt_num; id++)
	{
		if (clnt_lst[id].fd == clnt_fd)
			return (id);
	}
	return (LEFT_ONE);
}

void	initClientInfo(Client *sender)
{
	if (sender->buf_len == 0)
		sender->buf_len = BUFLEN;
	if (sender->buffer == NULL)
	{
		sender->buffer = calloc(sender->buf_len, sizeof(char));
		if (sender->buffer == NULL)
			printFatalErrorExit();
	}
}

void	storeMsgToClientBuffer(char *msg, Client *clnt)
{
	int	total_buf_len = strlen(clnt->buffer) + strlen(msg);
	if (total_buf_len > clnt->buf_len - 1)	// 버퍼 길이가 모자랄 때
	{
		int	buf_increase_rate = total_buf_len / clnt->buf_len + 1;
		clnt->buf_len *= buf_increase_rate;

		char	*new_buf = calloc(clnt->buf_len, sizeof(char));
		if (new_buf == NULL)
			printFatalErrorExit();
							
		strcat(new_buf, clnt->buffer);
		strcat(new_buf,	msg);

		free(clnt->buffer);
		clnt->buffer = new_buf;
	}
	else										// 버퍼 길이가 충분할 때
		strcat(clnt->buffer, msg);
}

void	sendMsgToAllIfThereNewline(Client *clnt)
{
	char	*nl_loc = strstr(clnt->buffer, "\n");
	
	while (nl_loc)
	{
		int	clnt_id = findClientIdWithFd(clnt->fd);

		char	*msg = ft_substr(clnt->buffer, nl_loc + 1);
		char	*msg_with_prefix = calloc(strlen("client ") + ilen(clnt_id) + \
			strlen(": ") + strlen(msg) + 1, sizeof(char));
		
		strcat(msg_with_prefix, "client ");
		sprintf(msg_with_prefix + strlen("client "), "%d", clnt_id);
		strcat(msg_with_prefix, ": ");
		strcat(msg_with_prefix, msg);

		sendMsgToAll(msg_with_prefix);
		free(msg_with_prefix);
									
		char	*tmp = calloc(clnt->buf_len, sizeof(char));
		strcpy(tmp, nl_loc + 1);
		free(clnt->buffer);
		clnt->buffer = tmp;

		nl_loc = strstr(clnt->buffer, "\n");
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

	int	serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv_sock == -1)
		printFatalErrorExit();
	
	sockaddr_in	serv_addr;
	bzero(&serv_addr, sizeof(sockaddr_in));
	serv_addr.sin_family		= AF_INET;
	serv_addr.sin_port			= htons(atoi(argv[1]));
	serv_addr.sin_addr.s_addr	= htonl(INADDR_ANY);

	if (bind(serv_sock, (const struct sockaddr *)&serv_addr, sizeof(const struct sockaddr)) == -1)
		printFatalErrorExit();
	
	if (listen(serv_sock, 5) == -1)
		printFatalErrorExit();
	
	fd_set	readsets;
	FD_ZERO(&readsets);
	addNewFdToReadset(serv_sock, &readsets);

	clnt_lst = calloc(clnt_num, sizeof(Client));
	if (clnt_lst == NULL)
		printFatalErrorExit();
	
	while (1)
	{
		fd_set	readsets_cpy = readsets;
		int		select_returned = select(fd_max + 1, &readsets_cpy, 0, 0, NULL);

		if (select_returned == -1)
			printFatalErrorExit();
		if (select_returned == 0)
			continue ;
		
		for (int fd = 0; fd < fd_max + 1; fd++)
		{
			if (FD_ISSET(fd, &readsets_cpy))
			{
				if (fd == serv_sock)	// connection request from client
				{
					sockaddr_in	clnt_addr;
					socklen_t	clnt_addr_len;
					
					int			clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_len);
					if (clnt_sock == -1)
						printFatalErrorExit();
					
					addNewFdToReadset(clnt_sock, &readsets);
					sendNewClientMsgToAll();
					addNewClientToArray(clnt_sock);
				}
				else					// msg from client
				{
					int		sender_id = findClientIdWithFd(fd);
					Client	*sender = &clnt_lst[sender_id];
					initClientInfo(sender);

					char	msg[BUFLEN];
					bzero(msg, BUFLEN);
					ssize_t	recv_returned = recv(fd, msg, BUFLEN - 1, 0);
					
					if (recv_returned == -1)
						printFatalErrorExit();
					else if (recv_returned == 0) // client disconnected from server
					{
						removeFdFromReadsetAndClose(fd, &readsets);
						recordClientDisconnectionAtArray(sender);
						sendClientLeftMsgToALL(sender_id);
					}
					else // get msg from client
					{
						storeMsgToClientBuffer(msg, sender);
						sendMsgToAllIfThereNewline(sender);
					}
				}
			}
		}
	}
}
