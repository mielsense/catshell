/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** task02, pool day 7
*/

char *my_strcat(char *dest, char *src)
{
    int counter;
    int end_of_dest;

    end_of_dest = 0;
    counter = 0;
    while (dest[end_of_dest] != '\0')
        end_of_dest++;
    while (src[counter] != '\0') {
        dest[end_of_dest + counter] = src[counter];
        counter++;
    }
    return dest;
}
