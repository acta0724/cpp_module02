/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwasakatsuya <iwasakatsuya@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:14:11 by kiwasa            #+#    #+#             */
/*   Updated: 2025/05/02 13:34:22 by iwasakatsuy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &rhs) const {
	return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->_value != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_value + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_value - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->_value * rhs.getRawBits() >> this->_fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits((this->_value << this->_fractionalBits) / rhs.getRawBits());
	return result;
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return(a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return(a > b) ? a : b;
}
