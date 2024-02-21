/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:06:57 by neleon            #+#    #+#             */
/*   Updated: 2024/02/05 18:45:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

fonction	get_next_line(file_descriptor):
	créer une chaîne de caractères pour stocker la ligne

	tant que "fin de ligne" n'est pas trouvée dans buffer:
		lire depuis file_descriptor dans un tampon temporaire de taille BUFFER_SIZE
		si la lecture ne renvoie rien (fin de fichier), sortir de la boucle
		ajouter le contenu du tampon temporaire à buffer
		vérifier si buffer contient maintenant "fin de ligne"

	si buffer contient "fin de ligne":
		copier les caractères de buffer jusqu'à "fin de ligne" dans la chaîne de ligne finale
		mettre à jour buffer pour enlever la partie copiée
	sinon:
		copier tout buffer dans la chaîne de ligne finale
		vider buffer

	retourner la chaîne de ligne finale (peut être vide si fin de fichier)

fin fonction

*/

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	*chars_rd;
// 	char		*buf;
// 	char		*line;
// 	int			rd;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	chars_rd = NULL;
// 	rd = 1;
// 	buf = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!buf)
// 		free_gnl(buf);
// 	while (rd = read(fd, buf, BUFFER_SIZE) > 0)
// 	{
// 		chars_rd[rd] = '/0';
// 		chars_rd = gnl_strjoin(chars_rd, buf);
// 		if (gnl_strchr(chars_rd, '\n'))
// 			break ;
// 	}
// }

char	*gnl_read_and_store(int fd, char *buf)
{
	char	*tmp;
	char	*new_buf;
	ssize_t bytes_read;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(tmp);
		if (bytes_read == 0)
			return (buf);
		else if (bytes_read < 0)
			return (NULL);
	}
    tmp[bytes_read] = '\0';
    new_buf = gnl_strjoin(buf, tmp);
    free(tmp);
    free(buf);
    return (new_buf);
}

// void	free_gnl(char *buf)
// {
// 	free(buf);
// 	return (NULL);
// }
