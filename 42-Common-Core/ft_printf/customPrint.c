/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customPrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:54:52 by neleon            #+#    #+#             */
/*   Updated: 2023/12/07 14:55:09 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exercice : Fonction customPrint
Objectif : Écrire une fonction nommée customPrint qui imite une version simplifiée de printf. Votre fonction doit être capable de gérer les formats de chaîne de caractères %s, les caractères %c, et les entiers %d.

Spécifications :

Le premier argument de la fonction sera une chaîne de format contenant du texte normal mélangé avec des spécificateurs de format commençant par %.
La fonction doit gérer les spécificateurs de format %s, %c, et %d uniquement.
Pour chaque spécificateur de format, la fonction doit imprimer le contenu correspondant des arguments suivants.
Prototype de la fonction :

c
Copy code
void customPrint(const char *format, ...);
Instructions :

Utilisez va_list pour gérer les arguments variables.
Parcourez la chaîne de format caractère par caractère.
Lorsque vous rencontrez un %, déterminez le spécificateur de format qui suit (s, c ou d) et imprimez l'argument correspondant.
Pour %s, imprimez la chaîne de caractères suivante.
Pour %c, imprimez le caractère suivant.
Pour %d, imprimez l'entier suivant.
N'oubliez pas d'utiliser va_end à la fin de la fonction.
Exemple d'utilisation :

c
Copy code
int main() {
    customPrint("Hello %s! You have %d new messages.\n", "Alice", 5);
    // Ceci devrait afficher "Hello Alice! You have 5 new messages."
    return 0;
}
Cet exercice vous aidera à comprendre comment printf analyse et traite les spécificateurs de format. Il constitue une excellente base pour aborder les fonctionnalités plus complexes de printf.
*/
