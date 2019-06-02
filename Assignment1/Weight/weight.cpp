#include <iostream>
#include <string>
#include <sstream>

// This function converts the weight to either pounds or kilos. It takes in the name, weight and the units inputed. if the weight is in kilos, it converts to pounds and vise versa. //
void convert(std::string input_name, double input_weight, std::string input_unit)
{
    if (input_unit == " Pounds" || input_unit == "pounds")
    {
        input_weight *= 0.454;
        std::cout<< "Hi "<<input_name<<" - you weigh "<<input_weight<<" kilos"<< std::endl << std::endl;
    }
    else if (input_unit == " Kilos" || input_unit == "kilos")
    {
        input_weight *= 2.205;
        std::cout<< "Hi "<<input_name<<" - you weigh "<<input_weight<<" pounds"<< std::endl<< std::endl;
    }
    else if (input_unit == " " || input_unit == "") // when no unit was entered //
    {
        std::cout<< "Not enough info to convert"<< std::endl<< std::endl;
    }
    else // when other than kilos and pounds are entered //
    {
        std::cout<< "Info was not entered correctly"<< std::endl<< std::endl;
    }
}

int main(int argc, const char * argv[])
{
    std::string answer,name,unit;
    double  weight;
    bool check = false;
    std::cout<<"---- Weight Conversion ----"<<std::endl;
    while(!check)
    {
        std::cout<<"Enter your name and weight(pounds/kilogram)"<< std::endl;
        getline(std::cin,answer);
        if(answer.compare("Exit")==0 || answer.compare("exit")==0)
        {
            check = true;
        }
        else
        {
            std::string temp;
            std::stringstream delimit(answer);
            getline(delimit,temp,' ');
            name = temp;
            getline(delimit,temp,' ');
            weight = stoi(temp);
            getline(delimit,temp,'\n');
            unit = temp;
            convert(name,weight,unit);
        }
    }
    std::cout << "Exiting..."<< std::endl;
    return 0;
}
