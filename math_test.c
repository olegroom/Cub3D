/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:19:31 by rosfryd           #+#    #+#             */
/*   Updated: 2021/02/15 13:22:10 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	main(void)
{
	float d = 2.3;
	printf("cos P = %f\n", cos(M_PI));
	printf("sin P = %f\n", sin(M_PI));
	printf("%f\n", d + cos(M_PI));
	printf("%f\n", d + cos(M_PI)/2);
	printf("%f\n", d + cos(M_PI)/4);
	printf("%f\n", d + cos(M_PI)/6);
	return (0);
}