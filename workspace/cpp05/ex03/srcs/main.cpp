#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main() {

    std::cout << "\n=== VALID CASES ===" << std::endl;

    // TEST 1: Intern creates ShrubberyCreationForm
    try
    {
        std::cout << "\n1. Intern creates ShrubberyCreationForm:\n" << std::endl;
        Intern intern;
        Bureaucrat bob("Bob", 130);
        
        AForm* form = intern.makeForm("shrubbery creation", "garden");
        if (form)
        {
            std::cout << *form << std::endl;
            std::cout << bob << " tries signing " << *form << std::endl;
            bob.signForm(*form);
            std::cout << "After sign: " << *form << std::endl;
            std::cout << bob << " tries executing " << *form << std::endl;
            bob.executeForm(*form);
            delete form;
        }
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }

    // TEST 2: Intern creates RobotomyRequestForm
    try
    {
        std::cout << "\n2. Intern creates RobotomyRequestForm:\n" << std::endl;
        Intern intern;
        Bureaucrat jim("Jim", 45);
        
        AForm* form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            std::cout << jim << " tries signing " << *form << std::endl;
            jim.signForm(*form);
            std::cout << "After sign: " << *form << std::endl;
            
            std::cout << "\nFirst execution attempt:" << std::endl;
            jim.executeForm(*form);
            std::cout << "\nSecond execution attempt:" << std::endl;
            jim.executeForm(*form);
            delete form;
        }
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }
    
    // TEST 3: Intern creates PresidentialPardonForm
    try
    {
        std::cout << "\n3. Intern creates PresidentialPardonForm:\n" << std::endl;
        Intern intern;
        Bureaucrat arthur("Arthur", 1);
        
        AForm* form = intern.makeForm("presidential pardon", "Ford Prefect");
        if (form)
        {
            std::cout << *form << std::endl;
            std::cout << arthur << " tries signing " << *form << std::endl;
            arthur.signForm(*form);
            std::cout << "After sign: " << *form << std::endl;
            std::cout << arthur << " tries executing " << *form << std::endl;
            arthur.executeForm(*form);
            delete form;
        }
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }
    
    // TEST 4: Same Intern creates multiple forms
    try
    {
        std::cout << "\n4. Same Intern creates multiple forms:\n" << std::endl;
        Intern intern;
        Bureaucrat master("Master", 1);
        
        AForm* shrub = intern.makeForm("shrubbery creation", "park");
        AForm* robot = intern.makeForm("robotomy request", "Android");
        AForm* pardon = intern.makeForm("presidential pardon", "Marvin");
        
        if (shrub && robot && pardon)
        {
            std::cout << "\nAll forms created:" << std::endl;
            std::cout << *shrub << std::endl;
            std::cout << *robot << std::endl;
            std::cout << *pardon << std::endl;
            
            std::cout << "\nSigning all forms:" << std::endl;
            master.signForm(*shrub);
            master.signForm(*robot);
            master.signForm(*pardon);
            
            std::cout << "\nExecuting all forms:" << std::endl;
            master.executeForm(*shrub);
            master.executeForm(*robot);
            master.executeForm(*pardon);
        }
        
        delete shrub;
        delete robot;
        delete pardon;
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== INVALID CASES ===\n" << std::endl;
    
    // TEST 5: Intern tries to create non-existent form
    try {
        std::cout << "\n1. Intern tries to create unknown form:\n" << std::endl;
        Intern intern;
        
        AForm* form = intern.makeForm("fake form", "nowhere");
        if (form == NULL)
            std::cout << "Successfully returned NULL for unknown form" << std::endl;
        else
            std::cout << "!! Error: Should have returned NULL" << std::endl;
        
        delete form; // Will delete NULL (safe)
    } catch (std::exception& e) {
        std::cout << "!! Error: " << e.what() << std::endl;
    }
    
    // TEST 6: Intern creates form with empty string
    try {
        std::cout << "\n2. Intern tries to create form with empty name:\n" << std::endl;
        Intern intern;
        
        AForm* form = intern.makeForm("", "target");
        if (form == NULL)
            std::cout << "Successfully returned NULL for empty form name" << std::endl;
        
        delete form;
    } catch (std::exception& e) {
        std::cout << "!! Error: " << e.what() << std::endl;
    }
    
    // TEST 7: Case sensitivity test (should fail because exact match required)
    try {
        std::cout << "\n3. Intern tries with wrong case (should fail):\n" << std::endl;
        Intern intern;
        
        AForm* form1 = intern.makeForm("Shrubbery Creation", "test");
        AForm* form2 = intern.makeForm("ROBOTOMY REQUEST", "test");
        AForm* form3 = intern.makeForm("Presidential Pardon", "test");
        
        if (form1 == NULL && form2 == NULL && form3 == NULL)
            std::cout << "Correctly rejected wrong case form names" << std::endl;
        
        delete form1;
        delete form2;
        delete form3;
    } catch (std::exception& e) {
        std::cout << "!! Error: " << e.what() << std::endl;
    }
    
    // TEST 8: Memory management - Intern forms can be executed after Intern is destroyed
    try {
        std::cout << "\n4. Forms survive after Intern is destroyed:\n" << std::endl;
        AForm* form = NULL;
        {
            Intern intern;
            form = intern.makeForm("shrubbery creation", "memory_test");
            std::cout << "Intern going out of scope..." << std::endl;
        }
        
        if (form)
        {
            Bureaucrat bob("Bob", 130);
            std::cout << "\nForm after Intern destroyed: " << *form << std::endl;
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
        std::cout << "\nDestructors:" << std::endl;
    } catch (std::exception& e) {
        std::cout << "!! Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== END ===\n" << std::endl;
    return 0;
}