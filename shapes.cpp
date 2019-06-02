#include <iostream>
#include <string>

// This function prints to the user the information on the shapes they entered. //
int Shapes(std::string input)
{
    if (input == "Triangle" || input == "triangle")
    {
        std::cout<< "Area = (Base * Height) / 2 "<< std::endl<< std::endl;
        return 0;
    }
    else if (input == "Square" || input == "square")
    {
        std::cout<< "Area = length * length"<< std::endl;
        std::cout<< "Perimeter = 4 * length"<< std::endl<< std::endl;
        return 0;
    }
    else if (input == "Rectangle" || input == "rectangle")
    {
        std::cout<< "Area = length * width"<< std::endl;
        std::cout<< "Perimeter = (2 * length) + (2 * width)"<< std::endl<< std::endl;
        return 0;
    }
    else // Other than triangle, square or rectangle is inputed //
    {
        std::cout << "No information on this shape" << std::endl<< std::endl;
        return 0;
    }
}

int main(int argc, const char * argv[])
{
    std::cout<<"------Shape------"<<std::endl<<std::endl;
    std::string shape;
    int count=0; // The count keeps track of the number of shapes entered //
    bool check = false;
    while(!check)
    {
        count++;
        std::cout<< count << " Shape: ";
        std::cin>> shape;
        // if shape is equal to exit then the compare function will return 0 thus assigning true to check and break the loop. //
        if (shape.compare("Exit")== 0 || shape.compare("exit") == 0)
        {
            check = true;
            count--; // decrement count since no shape was entered //
        }
        else
        {
            Shapes(shape);
        }
    }
    std::cout <<std::endl<< count<< " shapes entered"<< std::endl << "Exiting..."<< std::endl;
    return 0;
}
