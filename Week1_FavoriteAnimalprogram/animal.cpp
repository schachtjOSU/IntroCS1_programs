/*****************************************************************
 * * Author: Jeffrey Schachtsick
 * * Date: 01/09/2015
 * * Description: Program to display users favorite animal
 * **************************************************************/
 
#include <iostream>
#include <string>

// a simple example program
int main()
{
    std::string faveAnimal;
    std::cout << "Please enter your favorite animal" << std::endl;
    std::cin >> faveAnimal;
    std::cout << "Your favorite animal is the " << faveAnimal;
    std::cout << "." << std::endl;

    system("pause");
    return 0;
}
