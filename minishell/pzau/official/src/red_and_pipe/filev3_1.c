#include "../../header/header.h"

int	abrir_arquivo(char *caminho_arquivo)
{
	int	fd;

	fd = open(caminho_arquivo, O_RDONLY);
	if (fd == -1)
		perror("Erro ao abrir o arquivo");
	return (fd);
}

char	*inicializar_buffer(size_t capacidade)
{
	char	*buffer;

	buffer = (char *)malloc(capacidade);
	if (!buffer)
		perror("Erro ao alocar memória");
	return (buffer);
}

char	*fechar_arquivo(int fd, char *conteudo)
{
	close(fd);
	if (conteudo)
		free(conteudo);
	return (NULL);
}

ssize_t	ler_conteudo(int fd, char **conteudo,
	size_t *total_lido, size_t *capacidade)
{
	ssize_t	bytes_lidos;

	bytes_lidos = read(fd, *conteudo + *total_lido, *capacidade - *total_lido);
	if (bytes_lidos > 0)
	{
		*total_lido += bytes_lidos;
		if (*total_lido == *capacidade)
		{
			*capacidade *= 2;
			*conteudo = (char *)realloc(*conteudo, *capacidade);
			if (!(*conteudo))
			{
				perror("Erro ao realocar memória");
				return (-1);
			}
		}
	}
	else if (bytes_lidos == -1)
		perror("Erro ao ler o arquivo");
	return (bytes_lidos);
}

char	*ler_arquivo(char *caminho_arquivo)
{
	char	*conteudo;
	int		fd;
	size_t	capacidade;
	size_t	total_lido;

	capacidade = 1024;
	total_lido = 0;
	fd = abrir_arquivo(caminho_arquivo);
	if (fd == -1)
		return (NULL);
	conteudo = inicializar_buffer(capacidade);
	if (!conteudo)
		return (fechar_arquivo(fd, NULL));
	while (ler_conteudo(fd, &conteudo, &total_lido, &capacidade) > 0)
		;
	if (conteudo && total_lido == 0)
		return (fechar_arquivo(fd, NULL));
	conteudo[total_lido] = '\0';
	close(fd);
	return (conteudo);
}
