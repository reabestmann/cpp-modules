#include <Bureaucrat.hpp>

int main() {

    std::cout << "\n=== VALID CASES ===" << std::endl;

    try
    {
        std::cout << "\n1. Creating Bureaucrat with average grade, incrementing once:\n" << std::endl;
        Bureaucrat one;
        std::cout << one << std::endl;
        one.incrementGrade();
        std::cout << "After increment: " << one << std::endl;

        std::cout << "\n2. Creating Bureaucrat with low grade, decrementing to lowest:\n" << std::endl;
        Bureaucrat two("loser", 149);
        std::cout << two << std::endl;
        two.decrementGrade();
        std::cout << "After decrement: " << two << std::endl;

        std::cout << "\n3. Creating Bureaucrat with high grade, incrementing to best:\n" << std::endl;
        Bureaucrat three("star", 2);
        std::cout << three << std::endl;
        three.incrementGrade();
        three.decrementGrade();
        three.incrementGrade();
        std::cout << "After increment, decrement, increment: " << three << std::endl;
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }
    
    
    try {
        std::cout << "\n4. creating copied & assigned bureaucrats: \n" << std::endl;
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Temp", 1);
        assigned = original;
        
        std::cout << "\nOriginal: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    
        original.incrementGrade();
        std::cout << "\nAfter modifying original grade: " << original << std::endl;
        std::cout << "Copy remains: " << copy << std::endl;
        std::cout << "\nDestructors:" << std::endl;
    } catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== INVALID CASES ===\n" << std::endl;
    
    try {
        std::cout << "\n1. Creating Bureaucrat with grade 0.... (should throw exception)\n" << std::endl;
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << "!! Error: Exception not caught: " << tooHigh << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n2. Creating Bureaucrat with grade 151.... (should throw exception)\n" << std::endl;
        Bureaucrat tooLow("TooLow", 151);
        std::cout << "!! Error: Exception not caught: " << tooLow << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n3. Incrementing Bureaucrat with grade 1\n" << std::endl;
    
    try {
        Bureaucrat best("Best", 1);
        std::cout << best << std::endl;
        std::cout << "trying to increment now.... (should throw exception)" << std::endl;
        best.incrementGrade();
        std::cout << "!! Error: Exception not caught:" << best << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n4. Decrementing Bureaucrat with grade 150\n" << std::endl;
    
    try {
        Bureaucrat worst("Worst", 150);
        std::cout << worst << std::endl;
        std::cout << "trying to decrement now.... (should throw exception)" << std::endl;
        worst.decrementGrade();
        std::cout << "!! Error: Exception not caught: " << worst << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n5. Multiple Exceptions in one try Block\n" << std::endl;
    
    try {
        Bureaucrat worker("Worker", 5);
        std::cout << worker << std::endl;
        
        for (int i = 0; i < 10; ++i) {
            worker.incrementGrade();
            std::cout << "Grade now: " << worker.getGrade() << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== END ===\n" << std::endl;
    return 0;
}
