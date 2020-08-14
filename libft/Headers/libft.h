/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:49:35 by qmebble           #+#    #+#             */
/*   Updated: 2019/10/14 13:18:29 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "colors.h"

# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)

/*
**	Debug malloc
**
** # define malloc(X) my_malloc( X, __FILE__, __LINE__, __FUNCTION__)
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dynamic_buffer
{
	unsigned int	overflow_counter;
	int				size_for_malloc;
	int				amount_chars;
}					t_dynamic_buffer;

/*
**					Fills the first len bytes of the memory area
**					with a character which code is indicated by argument c
**
**	@param			b	Block of memory
**	@param			c	Value for assignment
**	@param			len	amount of elements for assignment
**
**	@return			Changed block of memory
*/
void				*ft_memset(void *b, int c, size_t len);

/*
**					Nullifies each element of memory block (array)
**
**	@param			s	Block of memory (array)
**	@param			n	Amount of elements to nullify
**
**	@return			N/A
*/
void				ft_bzero(void *s, size_t n);

/*
**					Copies values from one block of memory (array) to another
**
**	@param			s1	Destination array
**	@param			s2	Source array
**	@param			n	amount of elements to copy
**
**	@return			Changed block of memory
*/
void				*ft_memcpy(void *s1, const void *s2, size_t n);

/*
**					Copies the contents of the memory region pointed to source
**					to the memory region pointed to destination.
**					The copy operation ends when count bytes are copied or
**					after copying the first occurrence of the character c.
**
**	@param			s1	Destiantion memory block
**	@param			s2	Source memory block
**	@param			c	Character to stop coping
**	@param			n	Number of bytes to copy
**
**	@return			A pointer to the end of the s1 region
**						if the c character was found
**					NULL if c is not in s2
*/
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);

/*
**					Copies len bytes from the source array (memory region)
**					to the destination array
**
**	@param			dst	Destiantion array
**	@param			src	Source array
**	@param			len	Amount if bytes for copy
**
**	@return			Pointer to array into which data is copied
*/
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
**					Finds the first occurance of a character in array
**					(memory region) for the first len bytes
**
**	@param			s	Source array
**	@param			c	Character to find for
**	@param			len	Amount of first bytes to search in
**
**	@return			Pointer to the character found or NULL if it is not found
*/
void				*ft_memchr(const void *s, int c, size_t n);

/*
**					Concatenates the string s1 and a copy of the string s2.
**					At the end of the modified string s1, the function sets
**					the null character.
**
**	@param			s1	String for concatenate with source string
**	@param			s2	Source string
**
**	@return			Concatenated s1
*/
char				*ft_strcat(char *restrict s1, const char *restrict s2);

/*
**					Copies elements from string src to string dst
**
**	@param			@dst	The string where the copy is made
**	@param			@src	Source string
**
**	@return			Changed destination string
*/
char				*ft_strcpy(char *dst, const char *src);

/*
**					Duplicates the string pointed to s1.
**					Memory for a duplicate row is allocated using
**					the malloc function
**
**	@param			s1	Source string
**
**	@return			Pointer to duplicated string or NULL if malloc error
*/
char				*ft_strdup(const char *s1);

/*
**					Adds to the string pointed to the destination argument,
**					the string pointed to the source argument, until the end
**					of line character is encountered or until n characters are
**					added.
**
**	@param			s1	Destiantion string
**	@param			s2	Source string
**
**	@return			pointer to destination string
*/
char				*ft_strncat(char *restrict s1, const char *restrict s2,
	size_t n);

/*
**					Copies the data from the source string to the destination
**					string, until the zero character is found or the number of
**					copied characters reaches the certain amount of characters.
**					In this case, the line terminator is not copied.
**
**	@param			dst	Destination string
**	@param			src	Source string
**	@param			len	Amount of characters to copy
**
**	@return			A pointer to modified destination string
*/
char				*ft_strncpy(char *dst, const char *src, size_t len);

/*
**					Searches for the first occurrence of a character in a string
**
**	@param			s	String to search in
**	@param			c	Character to search for
**
**	@return			Pointer to the character if it is found, otherwise NULL
*/
char				*ft_strchr(const char *s, int c);

/*
**					Searches for the last occurrence of a character in a string
**
**	@param			s	String to search in
**	@param			c	Character to search for
**
**	@return			Pointer to character if it is found, otherwise NULL
*/
char				*ft_strrchr(const char *s, int c);

/*
**					Locates the first occurrence of the null-terminated
**					string s2 in the string s2. Characters that appear
**					after a `\0' character are not searched.
**
**	@param			s1	A string where to search
**	@param			s2	A string to search for
**
**	@return			A pointer to first occurrence if it is found, NULL otherwise
*/
char				*ft_strstr(const char *s1, const char *s2);

/*
**					Locates the first occurrence of the null-terminated
**					string s2 in the string s2 , where not more than len
**					characters are searched. Characters that appear after
**					a '\0' character are not searched.
**
**	@param			s1	A string where to search
**	@param			s2	A string to search for
**
**	@return			If s2 is an empty string, s1 is returned;
**					If s2 occurs nowhere in s1 , NULL is returned;
**					Otherwise a pointer to the first character of the
**					first occurrence of s2 is returned.
*/
char				*ft_strnstr(const char *s1, const char *s2, size_t len);

/*
**					Appends the NUL-terminated string src to the end of dst.
**					It will append at most size - strlen(dst) - 1 bytes.
**
**	@param			dst		Destination string
**	@param			src		Source string
**	@param			size	Range of search
**
**	@return			The total length of the string it tried to create
*/
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
	size_t size);

/*
**					Compares byte string s1 against byte string s2.
**					Both strings are assumed to be n bytes long.
**
**	@param			s1	First string
**	@param			s2	Second string
**	@param			n	Amount if bytes to compare
**
**	@return			0 if the two strings are identical, otherwise
**					returns the difference between the first two differing bytes
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**					Lexicographically compare the
**					null-terminated strings s1 and s2.
**
**	@param			s1	First string
**	@param			s2	Secont string
**
**	@return			An integer greater than, equal to, or less than 0,
**					according as the string s1 is greater than, equal to,
**					or less than the string s2
*/
int					ft_strcmp(const char *s1, const char *s2);

/*
**					Lexicographically compare first n bytes of the
**					null-terminated strings s1 and s2.
**
**	@param			s1	First string
**	@param			s2	Secont string
**	@param			n	Amount of bytes to compare
**
**	@return			An integer greater than, equal to, or less than 0,
**					according as the string s1 is greater than, equal to,
**					or less than the string s2
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**					Counts amount of characters in any type variable
**					(Except float and double)
**
**	@param			num	Main value
**	@param			type Value type (int, short, char, long int, long long int)
**
**	@return			Amount of characters in main value
*/
unsigned int		ft_count_amount_characters(void *num, char *type);

/*
**					Converts string to integer
**
**	@param			str	Main string
**
**	@return			Number in string
*/
int					ft_atoi(const char *str);

/*
**					Checks if character is a letter
**
**	@param			c Character to check
**
**	@return			1 if character is a letter,
**					otherwise 0
*/
int					ft_isalpha(int c);

/*
**					Checks if character is a digit
**
**	@param			c Character to check
**
**	@return			1 if character is a digit,
**					otherwise 0
*/
int					ft_isdigit(int c);

/*
**					Checks if character is a letter or a digit
**
**	@param			c Character to check
**
**	@return			1 if character is a letter or a digit,
**					otherwise 0
*/
int					ft_isalnum(int c);

/*
**					Checks if character belongs to ascii table
**
**	@param			c Character to check
**
**	@return			1 if character belongs,
**					otherwise 0
*/
int					ft_isascii(int c);

/*
**					Checks if a character can be seen when printing
**
**	@param			c Character to check
**
**	@return			1 if character can be seen,
**					otherwise 0
*/
int					ft_isprint(int c);

/*
**					If lowercase character, capitalize it, otherwise do nothing
**
**	@param			c	Character to change
**
**	@return			Same character if it uppercase,
**					otherwite same character in lowercase
*/
int					ft_toupper(int c);

/*
**					If upper character, makes it lowercase, otherwise do nothing
**
**	@param			c	Character to change
**
**	@return			Same character if it lowercase,
**					otherwite same character in uppercase
*/
int					ft_tolower(int c);

/*
**					Counts amount of characters in string until '\0'
**
**	@param			s Main string
**
**	@return			Amount of characters
*/
size_t				ft_strlen(const char *s);

/*
**					Allocates (with malloc(3)) and returns a “fresh” memory
**					area. The memory allocated is initialized to 0.
**					If the allocation fails, the function returns NULL.
**
**	@param			size	The size of the memory that needs to be allocated.
**
**	@return			The allocated memory area.
*/
void				*ft_memalloc(size_t size);

/*
**					Takes as a parameter the address of a memory area that needs
**					to be freed with free(3), then puts the pointer to NULL.
**
**	@param			ap	A pointer’s address that needs its memory
**						freed and set to NULL.
**
**	@return			N/A
*/
void				ft_memdel(void **ap);

/*
**					Allocates (with malloc(3)) and returns a “fresh” string
**					ending with ’\0’. Each character of the string is
**					initialized at ’\0’. If the allocation fails the
**					function returns NULL.
**
**	@param			size	Size of new string
**
**	@return			The string allocated and initialized to 0.
*/
char				*ft_strnew(size_t size);

/*
**					Takes as a parameter the address of a string that need to be
**					freed with free(3), then sets its pointer to NULL.
**
**	@param			ap	The string’s address that needs to be freed and
**						its pointer set to NULL.
**
**	@return			N/A
*/
void				ft_strdel(char **as);

/*
**					Sets every character of the string to the value ’\0’.
**
**	@param			s	The string that needs to be cleared.
**
**	@return			N/A
*/
void				ft_strclr(char *s);

/*
**					Applies the function f to each character of the string
**					passed as argument. Each character is passed by address
**					to f to be modified if necessary.
**
**	@param			s	The string to iterate
**	@param			f	The function to apply to each character of s.
**
**	@return			N/A
*/
void				ft_striter(char *s, void (*f)(char *));

/*
**					Applies the function f to each character of the
**					string passed as argument, and passing its index
**					as first argument. Each character is passed by address
**					to f to be modified if necessary.
**
**	@param			s	The string to iterate.
**	@param			f	The function to apply to each character of s
**						and its index
**
**	@return			N/A
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
**					Applies the function f to each character of the string given
**					as argument to create a “fresh” new string (with malloc(3))
**					resulting from the successive applications of f.
**
**	@param			s	The string to map
**	@param			f	The function to apply to each character of s.
**
**	@return			The “fresh” string created from the successive
**					applications of f.
*/
char				*ft_strmap(char const *s, char (*f)(char));

/*
**					Applies the function f to each character of the
**					string passed as argument by giving its index as
**					first argument to create a “fresh” new string
**					(with malloc(3)) resulting from the successive
**					applications of f.
**
**	@param			s	The string to map.
**	@param			f	The function to apply to each character of
**						s and its index.
**
**	@return			The “fresh” string created from the
**					successive applications of f.
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
**					Lexicographical comparison between s1 and s2. If the 2
**					strings are identical the function returns 1,
**					or 0 otherwise.
**
**	@param			s1	The first string to be compared.
**	@param			s2	The second string to be compared.
**
**	@return			1 or 0 according to if the 2 strings are identical or not.
*/
int					ft_strequ(char const *s1, char const *s2);

/*
**					Lexicographical comparison between s1 and s2 up to len
**					characters or until a ’\0’ is reached. If the 2 strings
**					are identical, the function returns 1, or 0 otherwise.
**
**	@param			s1	The first string to be compared.
**	@param			s2	The second string to be compared.
**	@param			len	The maximum number of characters to be compared.
**
**	@return			1 or 0 according to if the 2 strings are identical or not.
*/
int					ft_strnequ(char const *s1, char const *s2, size_t len);

/*
**					Allocates (with malloc(3)) and returns a “fresh” substring
**					from the string given as argument. The substring begins at
**					index start and is of size len. If start and len aren’t
**					refering to a valid substring, the behavior is undefined.
**					If the allocation fails, the function returns NULL.
**
**	@param			s		The string from which create the substring.
**	@param			start	The start index of the substring.
**	@param			len		The substring length.
**
**	@return
*/
char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
**					Allocates (with malloc(3)) and returns a “fresh” string
**					ending with ’\0’, result of the concatenation of s1 and s2.
**					If the allocation fails the function returns NULL.
**
**	@param			s1	The prefix string.
**	@param			s2	The suffix string.
**
**	@return			The “fresh” string result of the concatenation
**					of the 2 strings.
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
**					Allocates (with malloc(3)) and returns a “fresh” string
**					ending with ’\0’, result of the concatenation of num amount
**					of strings
**
**	@param			num	Amount of strings to join
**	@param			...	Num strgins to join
**
**	@return			The “fresh” string result of the concatenation
**					of the num strings
*/
char				*ft_strjoin_n(int num, ...);

/*
**					Allocates (with malloc(3)) and returns a copy of the string
**					given as argument without whitespaces at the beginning or at
**					the end of the string. Will be considered as whitespaces the
**					following characters ’ ’, ’\n’ and ’\t’. If s has no
**					whitespaces at the beginning or at the end, the function
**					returns a copy of s. If the allocation fails the function
**					returns NULL.
**
**	@param			s	The string to be trimed.
**
**	@return			The “fresh” trimmed string or a copy of s.
*/
char				*ft_strtrim(char const *s);

/*
**					Allocates (with malloc(3)) and returns an array of “fresh”
**					strings (all ending with ’\0’, including the array itself)
**					obtained by spliting s using the character c as a delimiter.
**					If the allocation fails the function returns NULL.
**
**	@param			s	The string to split.
**	@param			c	The delimiter character
*/
char				**ft_strsplit(char const *s, char c);

/*
**					Allocate (with malloc(3)) and returns a “fresh” string
**					ending with ’\0’ representing the integer n given as
**					argument. If the allocation fails, the function returns
**					NULL.
**
**	@param			n	The integer to be transformed into a string.
**
**	@return			The string representing the integer passed as argument.
*/
char				*ft_itoa(int n);

/*
**					Outputs the character c to the standard output.
**
**	@param			c	The character to output.
**
**	@return			N/A
*/
void				ft_putchar(char c);

/*
**					Outputs the string c to the standard output.
**
**	@param			s	The string to output.
**
**	@return			N/A
*/
void				ft_putstr(char const *s);

/*
**					Outputs the character c to the standard output
**					followed by '\n'
**
**	@param			s	The string to output.
**
**	@return			N/A
*/
void				ft_putendl(char const *s);

/*
**					Outputs the number n to the standard output.
**
**	@param			n	The number to output.
**
**	@return			N/A
*/
void				ft_putnbr(int n);

/*
**					Outputs the char c to the file descriptor fd.
**
**	@param			c	The character to output.
**	@param			fd	The file descriptor.
**
**	@return			N/A
*/
void				ft_putchar_fd(char c, int fd);

/*
**					Outputs the string s to the file descriptor fd.
**
**	@param			s	The string to output.
**	@param			fd	The file descriptor.
**
**	@return			N/A
*/
void				ft_putstr_fd(char const *s, int fd);

/*
**					Outputs the string s followed by '\n' to the
**					file descriptor fd.
**
**	@param			s	The string to output.
**	@param			fd	The file descriptor.
**
**	@return			N/A
*/
void				ft_putendl_fd(char const *s, int fd);

/*
**					Outputs the nuber n to the file descriptor fd.
**
**	@param			n	The number to output.
**	@param			fd	The file descriptor.
**
**	@return			N/A
*/
void				ft_putnbr_fd(int n, int fd);

/*
**					Allocates (with malloc(3)) and returns a “fresh” link. The
**					variables content and content_size of the new link are
**					initialized by copy of the parameters of the function.
**					If the parameter content is NULL, the variable content
**					is initialized to NULL and the variable content_size is
**					initialized to 0 even if the parameter content_size isn’t.
**					The variable next is initialized to NULL. If the
**					allocation fails, the function returns NULL.
**
**	@param			content	The content to put in the new link.
**	@param			content_size	The size of the content of the new link.
**
**	@return			The new link.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
**					Takes as a parameter a link’s pointer address and frees the
**					memory of the link’s content using the function del given as
**					a parameter, then frees the link’s memory using free(3). The
**					memory of next must not be freed under any circumstance.
**					Finally, the pointer to the link that was just freed must be
**					set to NULL (quite similar to the function ft_memdel in the
**					mandatory part).
**
**	@param			alst	The adress of a pointer to a link that needs
**							to be freed.
**
**	@return			N/A
*/
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
**					Takes as a parameter the adress of a pointer to a link and
**					frees the memory of this link and every successors of
**					that link using the functions del and free(3). Finally
**					the pointer to the link that was just freed must be set
**					to NULL (quite similar to the function ft_memdel from the
**					mandatory part).
**
**	@param			alst	The address of a pointer to the first link of a
**							list that needs to be freed.
**
**	@return			N/A
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
**					Adds the element new at the beginning of the list.
**
**	@param			alst	The address of a pointer to the first link
**							of a list.
**	@param			new		The link to add at the beginning of the list.
**
**	@return			N/A
*/
void				ft_lstadd(t_list **alst, t_list *new);

/*
**					Iterates the list lst and applies the function f
**					to each link.
**
**	@param			lst	A pointer to the first link of a list.
**	@param			f	The address of a function to apply to each link of
**						a list.
**
**	@return			N/A
*/
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
**					Iterates a list lst and applies the function f to each
**					link to create a “fresh” list (using malloc(3)) resulting
**					from the successive applications of f. If the allocation
**					fails, the function returns NULL.
**
**	@param			lst	A pointer’s to the first link of a list.
**	@param			f	The address of a function to apply to each link
**						of a list.
**
**	@return			The new list.
*/
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**					Fixes wrong case (upper / lower) in string
**
**	@param			s	String which need to be fixed
**
**	@return			Fixed string
*/
char				*ft_strfix(char *s);

/*
**					Allocates (with malloc(3)) new string and copies from
**					source string characters on positions from start to end
**
**	@param			s		Source string
**	@param			start	Start position
**	@param			end		End position
**
**	@return			New string with given range of bytes
*/
char				*ft_mascut(char *s, int start, int end);

/*
**					Changes the size of the allocated memory pointed to s
**					to the new value specified by the newsize parameter.
**					The size of newsize is given in bytes and may be more or
**					less than the original. A pointer to the memory block is
**					returned, since it may be necessary to move the block as
**					its size increases. In this case, the contents of the old
**					block are copied to the new block and the information is
**					not lost. If there is not enough free memory to allocate
**					a newsize block in the heap, a null pointer is returned.
**
**	@param			s		Memory block to change
**	@param			size	Amount of bytes to change
**
**	@return			N/A
*/
void				*ft_realloc(void *s, int size);

/*
**					Equals to math_abs()
**
**	@param			s	Number to check
**
**	@return			If number < 0, returns number *= -1,
**					otherwise returns the same number
*/
double				ft_abs(double s);

/*
**					Makes exponentiation of number n to power s
**					power can any number (-5, 0,75, 12, ...)
**
**	@param			n	Number for exponentiation
**	@param			s	Power for exponentiation
**
**	@return			Calculation result
*/
double				ft_pow(double n, double s);

/*
**					Makes new dynamic buffer with setting standard values
**
**	@param			N/A
**
**	@return			Buffer ready fot use
*/
t_dynamic_buffer	make_new_dynamic_buffer(void);

/*
**					Allocates memory and prints amount of allocated bytes,
**					file's and function's name where function malloc was used
*/
void				*my_malloc(size_t size, const char *file,
									int line, const char *func);

#endif
