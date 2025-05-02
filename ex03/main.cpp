/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwasakatsuya <iwasakatsuya@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:31:58 by iwasakatsuy       #+#    #+#             */
/*   Updated: 2025/05/02 13:43:04 by iwasakatsuy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 5.0f);

    Point inside(5.0f, 1.0f);
    Point outside(20.0f, 20.0f);
    Point onEdge(5.0f, 0.0f);
    Point onVertex(0.0f, 0.0f);

    std::cout << "Point inside: " << \
		(bsp(a, b, c, inside) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point outside: " << \
		(bsp(a, b, c, outside) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point on edge: " << \
		(bsp(a, b, c, onEdge) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point on vertex: " << \
		(bsp(a, b, c, onVertex) ? "Inside" : "Outside") << std::endl;

    return 0;
}
