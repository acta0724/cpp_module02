/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:35:48 by iwasakatsuy       #+#    #+#             */
/*   Updated: 2025/05/02 14:42:49 by kiwasa           ###   ########.fr       */
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

    if (cp1 == Fixed(0) || cp2 == Fixed(0) || cp3 == Fixed(0))
        return false;
    return ((cp1 > Fixed(0) && cp2 > Fixed(0) && cp3 > Fixed(0)) ||
            (cp1 < Fixed(0) && cp2 < Fixed(0) && cp3 < Fixed(0)));
}
