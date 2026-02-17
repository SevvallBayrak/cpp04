/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayrak <sbayrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 01:32:50 by sbayrak           #+#    #+#             */
/*   Updated: 2026/02/18 01:32:51 by sbayrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== ARRAY TEST ===" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];
    
    for (int i = 0; i < numAnimals; i++) {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
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