#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main() {

    std::cout << "\n=== VALID CASES ===" << std::endl;

    try
    {
        std::cout << "\n1. ShrubberyCreationForm with Bureaucrat grade 130:\n" << std::endl;
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("garden");
        std::cout << bob << " tries signing " << shrub << std::endl;
        bob.signForm(shrub);
        std::cout << "After sign: " << shrub << std::endl;
        std::cout << bob << " tries executing " << shrub << std::endl;
        bob.executeForm(shrub);
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n2. RobotomyRequestForm with Bureaucrat grade 45:\n" << std::endl;
        Bureaucrat jim("Jim", 45);
        RobotomyRequestForm robot("Bender");
        std::cout << jim << " tries signing " << robot << std::endl;
        jim.signForm(robot);
        std::cout << "After sign: " << robot << std::endl;
        
        std::cout << "\nFirst execution attempt:" << std::endl;
        jim.executeForm(robot);
        std::cout << "\nSecond execution attempt:" << std::endl;
        jim.executeForm(robot);
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "\n3. PresidentialPardonForm with Bureaucrat grade 1:\n" << std::endl;
        Bureaucrat arthur("Arthur", 1);
        PresidentialPardonForm pardon("Ford Prefect");
        std::cout << arthur << " tries signing " << pardon << std::endl;
        arthur.signForm(pardon);
        std::cout << "After sign: " << pardon << std::endl;
        std::cout << arthur << " tries executing " << pardon << std::endl;
        arthur.executeForm(pardon);
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "\n4. One Bureaucrat executing multiple forms:\n" << std::endl;
        Bureaucrat master("Master", 1);
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("Android");
        PresidentialPardonForm pardon("Marvin");
        
        std::cout << master << std::endl;
        
        std::cout << "\nSigning all forms:" << std::endl;
        master.signForm(shrub);
        master.signForm(robot);
        master.signForm(pardon);
        
        std::cout << "\nExecuting all forms:" << std::endl;
        master.executeForm(shrub);
        master.executeForm(robot);
        master.executeForm(pardon);
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== INVALID CASES ===\n" << std::endl;
    
    try {
        std::cout << "\n1. Grade too low to sign RobotomyRequestForm (needs 72, has 150):\n" << std::endl;
        Bureaucrat low("Lowly", 150);
        RobotomyRequestForm robot("Test");
        std::cout << low << " tries signing " << robot << " ... (should fail)" << std::endl;
        low.signForm(robot);
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n2. Grade too low to execute ShrubberyCreationForm (needs 137, has 138):\n" << std::endl;
        Bureaucrat signer("Signer", 130);
        Bureaucrat executor("Executor", 138);
        ShrubberyCreationForm shrub("test");
        
        std::cout << signer << " signs the form..." << std::endl;
        signer.signForm(shrub);
        std::cout << "\n" << executor << " tries executing " << shrub << " ... (should fail)" << std::endl;
        executor.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n3. Execute unsigned PresidentialPardonForm:\n" << std::endl;
        Bureaucrat high("High", 1);
        PresidentialPardonForm pardon("Unsigned");
        std::cout << high << " tries executing " << pardon << " without signing... (should fail)" << std::endl;
        high.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
        
    try
    {
        std::cout << "\n4. One Bureaucrat executing multiple forms (not high enough grade for PresidentialPardon):\n" << std::endl;
        Bureaucrat master("Master", 10);
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("Android");
        PresidentialPardonForm pardon("Marvin");
        
        std::cout << master << std::endl;
        
        std::cout << "\nSigning all forms:" << std::endl;
        master.signForm(shrub);
        master.signForm(robot);
        master.signForm(pardon);
        
        std::cout << "\nExecuting all forms:" << std::endl;
        master.executeForm(shrub);
        master.executeForm(robot);
        master.executeForm(pardon);
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== END ===\n" << std::endl;
    return 0;
}