#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void	SubjectTest()
{
    std::cout << "\n=== subject main ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
}

void	BasicTest()
{
    std::cout << "\n=== basic tests ==="
	<< "\n=== 1. create one of each using default Constructor:" << std::endl;
    Animal ogAnimal;
	Dog ogDog;
	Cat ogCat;
	
	std::cout <<"\n=== 2. create one of each using Copy Constructor:" << std::endl;
	Animal cpyAnimal(ogAnimal);
	Dog cpyDog(ogDog);
	Cat cpyCat(ogCat);
	
	std::cout <<"\n=== 3. create one of each & use assignment Operator:" << std::endl;
	Animal	assignedAnimal;
	Dog		assignedDog;
	Cat		assignedCat;
	assignedAnimal = cpyAnimal;
	assignedDog = ogDog;
	assignedCat = cpyCat;
	
	std::cout <<"\n=== 4. getType & makeSound:" << std::endl;
	std::cout << "ogAnimal type: " << ogAnimal.getType() << std::endl;
	std::cout << "cpyAnimal type: " << cpyAnimal.getType() << std::endl;
	std::cout << "assignedAnimal type: " << assignedAnimal.getType() << std::endl;
	ogAnimal.makeSound();
	std::cout << "\nogDog type: " << ogDog.getType() << std::endl;
	std::cout << "cpyDog type: " << cpyDog.getType() << std::endl;
	std::cout << "assignedDog type: " << assignedDog.getType() << std::endl;
	ogDog.makeSound();
	std::cout << "\nogCat type: " << ogCat.getType() << std::endl;
	std::cout << "cpyCat type: " << cpyCat.getType() << std::endl;
	std::cout << "assignedCat type: " << assignedCat.getType() << std::endl;
	ogCat.makeSound();

	std::cout <<"\n=== 5. Destructors (reversed order):" << std::endl;
}

void	PolymorphTest()
{
    std::cout << "\n=== Polymorphism Test ===" 
	<< "\n=== 1. create array" << std::endl;
    
	Animal* animals[4];
	animals[0] = new Animal();
	animals[1] = new Dog();
    animals[2] = new Cat();
	animals[3] = new Dog();

	std::cout << "\n=== 2. makeSound" << std::endl;
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << "\n=== 3. delete array" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i]; 
}

void	WrongTest()
{
    std::cout << "\n=== WrongAnimal Test (no virtual) ==="
	<< "\n=== 1. create WrongCat" << std::endl;
	const	WrongAnimal* wrong = new WrongCat();

	std::cout << "\n=== 2. call getType (expects WrongCat)" << std::endl;
	std::cout << wrong->getType() << std::endl;	
	
	std::cout << "\n=== 3. call makeSound (expects WrongAnimal)" << std::endl;
	wrong->makeSound();

	std::cout << "\n=== 4. delete WrongCat (expects incomplete destruction)" << std::endl;
	delete wrong;
}

int main()
{
    int choice;
    std::cout << "Select test:\n"
	<< "1 - Subject\n" 
	<< "2 - Basic\n"
	<< "3 - Polymorphism\n"
	<< "4 - WrongAnimal\n"
	<< "Enter choice: ";
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            SubjectTest();
            break;
        case 2:
            BasicTest();
            break;
        case 3:
			PolymorphTest();
			break;
		case 4:
            WrongTest();
            break;
        default:
            std::cout << "Invalid choice\n";
	}
    return 0;
}
