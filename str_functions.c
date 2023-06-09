#include "monty.h"

/**
 * _strcmp - Function that compares 2 strings
 * @s1: String 1 to compare
 * @s2: String 2 to compare
 * Return: 0 if s1 and s2 are equals
 * another value if they are different
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}

/**
 * char_in_string - Function that checks if a character is
 * present in a string
 * @str: string to search
 * @c: char to find
 * Return: 1 if character is found or 0 otherwise
*/
int char_in_string(char *str, char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtoky - Function that tokenizes a string based in delimiters
 * @str: string to tokenize
 * @delim: delimiters
 * Return: Pointer to the Firts token
*/
char *_strtoky(char *str, char *delim)
{
	static char *lastToken;
	char *tokenStart;
	int tokenLen = 0;

	if (str != NULL)
		lastToken = str;

	while (*lastToken && char_in_string(delim, *lastToken))
		lastToken++;

	if (*lastToken == '\0')
		return (NULL);

	tokenStart = lastToken;

	while (*lastToken && !char_in_string(delim, *lastToken))
	{
		lastToken++;
		tokenLen++;
	}

	*lastToken = '\0';

	lastToken++;

	return (tokenStart);
}
