/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwasakatsuya <iwasakatsuya@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:35:48 by iwasakatsuy       #+#    #+#             */
/*   Updated: 2025/05/02 13:36:03 by iwasakatsuy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossProduct(const Point &p1, const Point &p2, const Point &p3) {
    return ((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
            (p2.getY() - p1.getY()) * (p3.getX() - p1.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed cp1 = crossProduct(a, b, point);
    Fixed cp2 = crossProduct(b, c, point);
    Fixed cp3 = crossProduct(c, a, point);

    if (cp1 == 0 || cp2 == 0 || cp3 == 0)
        return false;
    return ((cp1 > 0 && cp2 > 0 && cp3 > 0) ||
            (cp1 < 0 && cp2 < 0 && cp3 < 0));
}
