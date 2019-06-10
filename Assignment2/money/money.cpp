// Prissha Krishna Moorthy, 1001354261
#include <iostream>
#include <string>
#include <vector>

// Enters the information of the conversion center
class Office{
    std::string first_name,second_name,manager_name;
public:
    Office()
    {}
    Office (std::string first_name,std::string second_name,std::string manager_name)
    {
        this->first_name = first_name;
        this->second_name= second_name;
        this->manager_name=manager_name;
    }

    std::string get_firstname()
    {
        return first_name;
    }
    std::string get_secondname()
    {
        return second_name;
    }
    std::string get_managername()
    {
        return manager_name;
    }
};

// Conversion class is where the currency conversion takes place
class conversion{
    Office p;
public:
    conversion()
    {}

    float convert1(Office P)
    {
        float value;
        std::string currency;
        std::cout<< std::endl<<"Welcome to "<<P.get_firstname()<<" "<< P.get_secondname()<<". Please contact the manager " << P.get_managername()<< " if you have any complaints. What currency are you converting to dollars and how much? ";
        std::cin>>value>>currency;

        if(currency == "yen")
        {
            value = 0.0091*value; // 1 yen = 0.0091 dollar according to google on feb 5th
        }
        else if(currency == "rupee")
        {
            value = 0.014*value; // 1 rupee = 0.014 dollar according to google on feb 5th
        }
        else
        {
            std::cout<<"We do not convert the "<<currency<<" currency here. Sorry."<<std::endl;
            return 0;
        }
        std::cout<<"Here you go: $ "<<value<<std::endl;
        return value;
    }

    float convert2(Office P)
    {
        float value;
        std::string currency;
        std::cout<< std::endl<< "Welcome to "<<P.get_firstname()<< " " <<P.get_secondname()<<". Please contact the manager " << P.get_managername()<< " if you have any complaints. What currency are you converting to dollars and how much? ";
        std::cin>>value>>currency;

        if(currency == "ringgit")
        {
            value = 0.25*value; //  1 ringgit = 0.25 dollar according to google on feb 5th
        }
        else if(currency == "peso")
        {
            value = 0.053*value; // 1 peso = 0.053 dollar according to google on feb 5th
        }
        else
        {
            std::cout<<"We do not convert the "<<currency<<" currency here. Sorry."<<std::endl;
            return 0;
        }
        std::cout<<"Here you go: $ "<<value<<std::endl<<std::endl; // Displays the converted dollar
        return value;
    }
};


int main(int argc, const char * argv[]) {
    std::string first_name1,second_name1,manager1,first_name2,second_name2,manager2,location;
    bool check= false;
    std::vector<float> dollars;
    float total_value = 0;

    std::cout<<"Enter name of exchange office and manager: ";
    std::cin>>first_name1>>second_name1>>manager1;
    std::cout<<"Enter name of exchange office and manager: ";
    std::cin>>first_name2>>second_name2>>manager2;

    Office A1(first_name1,second_name1,manager1); // Entering information of each conversion center in class Office
    Office A2(first_name2,second_name2,manager2);
    conversion t;

    // loop ends if the user input exit for their location since it assigns true to check
    while (!check)
    {
        std::cout<<std::endl<<"Hello traveler! Where are you in the airport? ";
        std::cin>>location;
        if (location == "North" || location == "East" || location == "north" || location == "east")
        {
            dollars.push_back(t.convert1(A1)); // adds the converted currency to dollar to vector dollar
        }
        else if (location == "South" || location == "West" || location == "south" || location == "west")
        {
            dollars.push_back(t.convert2(A2)); // adds the converted currency to dollar to vector dollar
        }
        else if (location == "Exit" || location == "exit")
        {
            check = true;
        }
        else
        {
            std::cout<<"Invalid entry. Enter 'North','South',East','West' or 'Exit'. Try Again"<<std::endl;
        }
    }

    for(int i=0;i<dollars.size();i++)
    {
        total_value += dollars[i]; // Adds every dollar that is converted
    }
    std::cout<<"$$$Total dollars given out: $"<<total_value<<std::endl;
    std:: cout<< "Exiting..."<<std::endl;
    return 0;
}
