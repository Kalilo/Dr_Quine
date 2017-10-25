/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 09:23:10 by khansman          #+#    #+#             */
/*   Updated: 2017/10/24 09:23:11 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

# define FT_MAIN(X) int main() { X }

// extern const char *__progname;

FT_MAIN(
	printf("this is a test main\n");
	// printf("name: %s\n", strchr(__progname, '.') + 1 );
)