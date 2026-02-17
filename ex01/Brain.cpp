/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevvalbayrak <sevvalbayrak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:07:20 by sevvalbayra       #+#    #+#             */
/*   Updated: 2026/02/18 01:07:36 by sevvalbayra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created!" << std::endl;
    for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "";
	}
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called (Deep Copy)" << std::endl;
    for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed!" << std::endl;
}

std::string Brain::setIdea(int x, const std::string& idea)
{
    if (x < 0 || x > 99)
        return "Error: Index out of bounds! Valid range is 0-99.";
    this->ideas[x] = idea;
    return "Success: Idea stored in memory slot!";
}

const std::string &Brain::getIdea(int x) const
{
    static const std::string errorMsg = "Error: Index out of bounds! Cannot retrieve idea.";
    if (x < 0 || x > 99)
        return errorMsg;
    return this->ideas[x];
}