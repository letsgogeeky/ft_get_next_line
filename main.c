#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "get_next_line.h"
extern int errno;

int	main(void)
{
	// int	read_size;
	int fd;
	// char *buffer = (char *)malloc(1024);
	char path[] = "./test.txt";
	char	*str;
	int		line_count;
	// int buffer_size;
	// int buffer_idx;

	// buffer_size = 100;
	// #ifdef BUFFER_SIZE
	// 	printf("Buffer size: %d\n", BUFFER_SIZE);
	// 	buffer_size = BUFFER_SIZE;
	// #endif
	// printf("Buffer size out of ifdef scope: %d\n", buffer_size);
	fd = open(path, O_RDONLY);
	// printf("File descriptor: %d\n", fd);
	// read_size = read(fd, buffer, 1);
	// buffer_idx = 0;
	// while (read_size == 1 && buffer[0] && buffer[0] != '\n')
	// {
	// 	printf("%c", buffer[0]);
	// 	read_size = read(fd, buffer, 1);
	// 	buffer[read_size] = '\0';
	// 	buffer_idx++;
	// }
	// printf("Updated file descriptor: %d\n", fd); 
	// if (read_size == -1)
	// {
	// 	printf("Error: %d\nBad File: %d\nInvalid Argument: %d\nI/O error: %d\n", errno, EBADF, EINVAL, EIO);
	// 	return (0);
	// }
	// printf("Characters read: %d\n", read_size);
	// printf("File contents: \n%s\n", buffer);
	line_count = 0;
	str = get_next_line(fd);
	while (str)
	{
		line_count++;
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("\n==========\nFound %d lines\n", line_count);
	
	return (0);
}