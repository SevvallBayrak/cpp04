/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayrak <sbayrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:08:00 by sevvalbayra       #+#    #+#             */
/*   Updated: 2026/02/18 01:32:05 by sbayrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== PDF TEST ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n=== ARRAY TEST ===" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];
    
    for (int idx = 0; idx < numAnimals; idx++) {
        if (idx < numAnimals / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    for (int idx = 0; idx < numAnimals; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }

    for (int idx = 0; idx < numAnimals; idx++) {
        delete animals[idx];
    }

    std::cout << "\n=== DEEP COPY WITH BRAIN TEST ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I love bones!");
    dog1.getBrain()->setIdea(1, "Chase cats!");
    
    std::cout << "Dog1 original ideas:" << std::endl;
    std::cout << "  [0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "  [1]: " << dog1.getBrain()->getIdea(1) << std::endl;

    Dog dog2 = dog1; 
    std::cout << "\nDog2 (copy) has same ideas:" << std::endl;
    std::cout << "  [0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "  [1]: " << dog2.getBrain()->getIdea(1) << std::endl;

    dog2.getBrain()->setIdea(0, "I prefer sticks!");
    dog2.getBrain()->setIdea(1, "Play with humans!");
    
    std::cout << "\nAfter changing dog2's brain:" << std::endl;
    std::cout << "Dog1 [0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 [0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "-> Different! This proves DEEP COPY!" << std::endl;

    return 0;
}