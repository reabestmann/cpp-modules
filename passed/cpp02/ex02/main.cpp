/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:02:43 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/24 19:34:08 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
/*
int main(void)
{
    std::cout << "\n========== CONSTRUCTOR TESTS ==========\n" << std::endl;
    
    Fixed a;                    // Default constructor
    Fixed const b(10);           // Int constructor
    Fixed const c(42.42f);       // Float constructor
    Fixed d(b);                  // Copy constructor
    
    std::cout << "\n========== ASSIGNMENT OPERATOR ==========\n" << std::endl;
    Fixed e;
    e = c;                       // Copy assignment operator
    
    std::cout << "\n========== BASIC OUTPUT ==========\n" << std::endl;
    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 10): " << b << std::endl;
    std::cout << "c (float 42.42f): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;
    std::cout << "e (assigned from c): " << e << std::endl;
    
    std::cout << "\n========== COMPARISON OPERATORS ==========\n" << std::endl;
    Fixed x(5);
    Fixed y(10);
    Fixed z(5);
    
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x > y: " << (x > y) << " (should be 0)" << std::endl;
    std::cout << "x < y: " << (x < y) << " (should be 1)" << std::endl;
    std::cout << "x >= z: " << (x >= z) << " (should be 1)" << std::endl;
    std::cout << "x <= y: " << (x <= y) << " (should be 1)" << std::endl;
    std::cout << "x == z: " << (x == z) << " (should be 1)" << std::endl;
    std::cout << "x != y: " << (x != y) << " (should be 1)" << std::endl;
    
    std::cout << "\n========== ARITHMETIC OPERATORS ==========\n" << std::endl;
    Fixed n1(10);
    Fixed n2(3);
    Fixed n3(2.5f);
    
    std::cout << "n1 = " << n1 << ", n2 = " << n2 << ", n3 = " << n3 << std::endl;
    std::cout << "n1 + n2 = " << (n1 + n2) << " (should be 13)" << std::endl;
    std::cout << "n1 - n2 = " << (n1 - n2) << " (should be 7)" << std::endl;
    std::cout << "n1 * n2 = " << (n1 * n2) << " (should be 30)" << std::endl;
    std::cout << "n1 / n2 = " << (n1 / n2) << " (should be 3.333...)" << std::endl;
    std::cout << "n3 * 2 = " << (n3 * Fixed(2)) << " (should be 5)" << std::endl;
    std::cout << "n3 / 2 = " << (n3 / Fixed(2)) << " (should be 1.25)" << std::endl;
    
    std::cout << "\n========== INCREMENT/DECREMENT ==========\n" << std::endl;
    Fixed i(5);
    std::cout << "i starts as: " << i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i after: " << i << std::endl;
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i after: " << i << std::endl;
    std::cout << "--i: " << --i << std::endl;
    std::cout << "i after: " << i << std::endl;
    std::cout << "i--: " << i-- << std::endl;
    std::cout << "i after: " << i << std::endl;
    
    std::cout << "\n========== MIN/MAX FUNCTIONS ==========\n" << std::endl;
    Fixed p(3.14f);
    Fixed q(2.71f);
    const Fixed r(100);
    const Fixed s(200);
    
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "min(p, q): " << Fixed::min(p, q) << std::endl;
    std::cout << "max(p, q): " << Fixed::max(p, q) << std::endl;
    
    std::cout << "\n--- Testing const versions ---" << std::endl;
    std::cout << "r = " << r << ", s = " << s << std::endl;
    std::cout << "min(r, s): " << Fixed::min(r, s) << std::endl;
    std::cout << "max(r, s): " << Fixed::max(r, s) << std::endl;
    
    std::cout << "\n========== EDGE CASES ==========\n" << std::endl;
    
    // Zero
    Fixed zero;
    Fixed num(5);
    std::cout << "zero = " << zero << ", num = " << num << std::endl;
    std::cout << "zero + num = " << (zero + num) << std::endl;
    std::cout << "num - zero = " << (num - zero) << std::endl;
    std::cout << "num * zero = " << (num * zero) << std::endl;
    
    // Division by zero (uncomment to test crash - subject says it's ok to crash)
    // std::cout << "num / zero = " << (num / zero) << std::endl;
    
    // Negative numbers
    Fixed neg1(-5);
    Fixed neg2(-2.5f);
    std::cout << "\nneg1 = " << neg1 << ", neg2 = " << neg2 << std::endl;
    std::cout << "neg1 + neg2 = " << (neg1 + neg2) << std::endl;
    std::cout << "neg1 - neg2 = " << (neg1 - neg2) << std::endl;
    std::cout << "neg1 * neg2 = " << (neg1 * neg2) << std::endl;
    std::cout << "neg1 / neg2 = " << (neg1 / neg2) << std::endl;
    
    // Mixed signs
    Fixed pos(10);
    std::cout << "\npos = " << pos << ", neg1 = " << neg1 << std::endl;
    std::cout << "pos + neg1 = " << (pos + neg1) << std::endl;
    std::cout << "pos - neg1 = " << (pos - neg1) << std::endl;
    std::cout << "pos * neg1 = " << (pos * neg1) << std::endl;
    std::cout << "pos / neg1 = " << (pos / neg1) << std::endl;
    
    std::cout << "\n========== SUBJECT TEST ==========\n" << std::endl;
    Fixed subj_a;
    Fixed const subj_b(Fixed(5.05f) * Fixed(2));
    
    std::cout << subj_a << std::endl;
    std::cout << ++subj_a << std::endl;
    std::cout << subj_a << std::endl;
    std::cout << subj_a++ << std::endl;
    std::cout << subj_a << std::endl;
    std::cout << subj_b << std::endl;
    std::cout << Fixed::max(subj_a, subj_b) << std::endl;
    
    std::cout << "\n========== DESTRUCTORS ==========\n" << std::endl;
    return 0;
} */

