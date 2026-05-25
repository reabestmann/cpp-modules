#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
    std::cout << "\n=== subject main (check for leaks) ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	//const Animal* k = new Animal();
	//Animal a;
	delete j;
	delete i;
	//delete k;

	return 0;
}

/*
void	BasicTest()
{
    std::cout << "\n=== basic tests ==="
	<< "\n=== 1. default Constructor:" << std::endl;
	Dog ogDog;
	Cat ogCat;
	
	std::cout <<"\n=== 2. Copy Constructor:" << std::endl;
	Dog cpyDog(ogDog);
	Cat cpyCat(ogCat);
	
	std::cout <<"\n=== 3. assignment Operator:" << std::endl;
	Dog		assignedDog;
	Cat		assignedCat;
	assignedDog = ogDog;
	assignedCat = cpyCat;
	
	std::cout <<"\n=== 4. getType & makeSound:" << std::endl;
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

void DeepCopyTest()
{
    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Bone");
    dog1.getBrain()->setIdea(1, "Chase tail");
    
    Dog dog2(dog1);
    
    dog2.getBrain()->setIdea(0, "Ball");
    
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    if (dog1.getBrain()->getIdea(0) !=  dog2.getBrain()->getIdea(0))
        std::cout << "✓ Deep copy works! Different brains." << std::endl;
    else
        std::cout << "✗ Shallow copy! Same brain." << std::endl;
}

void	WrongTest()
{
    std::cout << "\n=== PART 4: WrongAnimal Test (shallow copy) ===";
	WrongCat cat1;
    cat1.getBrain()->setIdea(0, "catch mice");
    WrongCat cat2(cat1);
    cat2.getBrain()->setIdea(0, "do catnip");
    
    std::cout << "\nCat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;
    
    if (cat1.getBrain()->getIdea(0) == cat2.getBrain()->getIdea(0))
        std::cout << "→ Shallow copy! Same brain." << std::endl;
    else
        std::cout << "→ Deep Copy! Different brains." << std::endl;
}

void	AllTests()
{
	std::cout << "\n=== ALL TESTS===\n";
	SubjectTest();
	BasicTest();
	DeepCopyTest();
	WrongTest();
	std::cout << "\n=== ALL TESTS COMPLETED\n";
}

int main()
{
    int choice;
    std::cout << "Select test:\n"
	<< "0. All\n"
	<< "1. Subject\n" 
	<< "2. Basic\n"
	<< "3. DeepCopy\n"
	<< "4. WrongAnimal\n"
	<< "Enter choice: ";
    std::cin >> choice;
    
    switch (choice) {
		case 0:
			AllTests();
			break;
        case 1:
            SubjectTest();
            break;
        case 2:
            BasicTest();
            break;
        case 3:
			DeepCopyTest();
			break;
		case 4:
            WrongTest();
            break;
        default:
            std::cout << "Invalid choice. Running ALL tests by default\n";
			AllTests();
	}
    return 0;
}*/
