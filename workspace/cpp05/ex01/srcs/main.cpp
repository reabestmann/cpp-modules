#include <Bureaucrat.hpp>
#include <Form.hpp>

int main() {

    std::cout << "\n=== VALID CASES ===" << std::endl;

    try
    {
        std::cout << "\n1. Default Bureaucrat & Default Form:\n" << std::endl;
        Bureaucrat one;
        Form    f;
        std::cout << one << " tries signing " << f << std::endl;
        one.signForm(f);
        std::cout << "After sign: " << f << std::endl;

        std::cout << "\n2. Custom Bureaucrat & Default Form:\n" << std::endl;
        Bureaucrat two("ok", 20);
        Form    f2;
        std::cout << two << " tries signing " << f2 << std::endl;
        two.signForm(f2);
        std::cout << "After sign: " << f2 << std::endl;

        std::cout << "\n3. Custom Bureaucrat & Custom Form:\n" << std::endl;
        Bureaucrat three("bla", 89);
        Form f3("easy", 100, 40);
        std::cout << three << " tries signing " << f3 << std::endl;
        three.signForm(f3);
        std::cout << "After sign: " << f3 << std::endl;
        std::cout << "\nDestructors:" << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }
    
    
    try {
        std::cout << "\n4. creating copied & assigned forms: \n" << std::endl;
        Form original("Original", 42, 20);
        Form copy(original);
        Form assigned("Temp", 1, 2);
        assigned = original;
        
        std::cout << "\nOriginal: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    
        Bureaucrat b("guy", 41);
        original.beSigned(b);
        std::cout << "\nAfter signing original Form: " << original << std::endl;
        std::cout << "Copy remains: " << copy << std::endl;
        std::cout << "\nDestructors:" << std::endl;
    } catch (std::exception& e) {
        std::cout << "!! Error: Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n=== INVALID CASES ===\n" << std::endl;
    
    try {
        std::cout << "\n1. Creating Form with signGrade 0.... (should throw exception)\n" << std::endl;
        Form tooHigh("TooHigh", 0, 10);
        std::cout << "!! Error: Exception not caught: " << tooHigh << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n2. Creating Form with exeGrade 151.... (should throw exception)\n" << std::endl;
        Form tooLow("TooLow", 36, 151);
        std::cout << "!! Error: Exception not caught: " << tooLow << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n3. Bureaucrat tries to sign with too low grade\n" << std::endl;
    
    try {
        Bureaucrat best("new", 100);
        Form    hard("hard", 99, 100);
        std::cout << '\n' << best << " tries to sign " << hard << " ... (should fail)" << std::endl;
        best.signForm(hard);
        best.incrementGrade();
        std::cout << "\nincrementing Bureaucrat once and try to sign again.... (should work)" << std::endl;
        best.signForm(hard);
        std::cout << "After sign: " << hard << std::endl;
        std::cout << "\nDestructors:" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "!! Unexpected Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n4. One Bureaucrat tries signing multiple Forms\n" << std::endl;
    
    try {
        Bureaucrat worker("Worker", 50);
        std::cout << worker << "\n\nCreating forms..." << std::endl;
        Form forms[] =
        {
            Form("easy", 100, 50),
            Form("medium", 75, 40),
            Form("hard", 50, 30),
            Form("expert", 30, 20),
            Form("impossible", 10, 5)
        };

        for (int i = 0; i < 5; ++i) {
            std::cout << std::endl;
            worker.signForm(forms[i]);
            std::cout << "After sign attempt: " << forms[i] << std::endl;
        }
        std::cout << "\nDestructors:" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "!!Unexpected Error : " << e.what() << std::endl;
    }
    
    std::cout << "\n=== END ===\n" << std::endl;
    return 0;
}
