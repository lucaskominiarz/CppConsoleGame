 

#include <iostream>

int main()
{
    /*
    int number = 4;

    if (number % 2 == 0) {
        std::cout << "Le nombre est pair";
    }
    else {
        std::cout << "Le nombre est impair";
    }
    */
    srand(time(NULL));
    constexpr int b1 = { 0 };
    constexpr int b2 = { 10 };
    constexpr int size{ 10 };

    int aNumbers[size] = { 1,2,3,4,5,6,7,8,9,10};

    int number = aNumbers[rand() % size - 1];
    
    //int number = rand() % b2 + b1;
    int input{ 0 };
    

    while (input != number) {

        std::cout << "Entrez un nombre " ;
        std::cin >> input;

        if (number == input) {
            std::cout << std::endl << "Bien joue, le nombre etait " << input << std::endl;
            break;
        }

        std::cout << std::endl <<((number > input) ? "Plus haut que " : "Plus bas que ") << input << std::endl;
    }
}

 