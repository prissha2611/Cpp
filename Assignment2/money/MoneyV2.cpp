// This code is the edited version of the original Money.cpp after a better
// understanding of object oriented concept
// Revised on 6/10/2019 by Prissha Krishna Moorthy
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Enters the information of the conversion center
class Office{
    std::string company_name,manager_name;

public:
    Office()
    {}
    Office (std::string company_name,std::string manager_name)
    {
        this->company_name = company_name;
        this->manager_name=manager_name;
    }
    std::string get_companyname()
    {
        return company_name;
    }
    std::string get_managername()
    {
        return manager_name;
    }
};


class Conversion_center{
    std::vector<Office*> Conversion_Offices;
public:
    Conversion_center(int num_office)
    {
        std::string company_name,manager,answer,intermediate;

        for(int i = 0;i<num_office;i++)
        {
            std::cout<<"Enter name of exchange office and manager: ";
            getline(std::cin,answer);
            std::stringstream delimit(answer);
            getline(delimit,intermediate,' ');
            company_name = intermediate;
            getline(delimit,intermediate,' ');
            company_name = company_name + ' ' + intermediate;
            getline(delimit,manager,'\n');

            Office *A1 = new Office(company_name,manager);
            Conversion_Offices.push_back(A1);
        }
    }
    // Conversion function is where the currency conversion takes place
    float Conversion(int office_num)
    {
        float value;
        std::string currency;
        std::cout<< std::endl<<"Welcome to "<<Conversion_Offices[office_num]->get_companyname()<<". Please contact the manager " <<Conversion_Offices[office_num]->get_managername()<< " if you have any complaints. What currency are you converting to dollars and how much? ";
        std::cin>>value>>currency;

        switch(office_num)
        {
            case 0: // for office in the North and East area
                if(currency == "yen")
                {
                    value = 0.0091*value; // 1 yen = 0.0091 dollar according to google on feb 5th
                    break;
                }
                else if(currency == "rupee")
                {
                    value = 0.014*value; // 1 rupee = 0.014 dollar according to google on feb 5th
                    break;
                }
            case 1: // for office in the South and West area
                if(currency == "ringgit")
                {
                    value = 0.25*value; //  1 ringgit = 0.25 dollar according to google on feb 5th
                    break;
                }
                else if(currency == "peso")
                {
                    value = 0.053*value; // 1 peso = 0.053 dollar according to google on feb 5th
                    break;
                }
            default: // When currency not available in all offices
                std::cout<<"We do not convert the "<<currency<<" currency here. Sorry."<<std::endl;
                return 0;
        }
        std::cout<<"Here you go: $ "<<value<<std::endl;
        return value;
    }
};


int main(int argc, const char * argv[]) {
    std::string location;
    bool check= false;
    float total_value = 0;

    Conversion_center A(2); // 2 represents the number of office

    // loop ends if the user input exit for their location since it assigns true to check
    while (!check)
    {
        std::cout<<std::endl<<"Hello traveler! Where are you in the airport? ";
        std::cin>>location;
        if (location == "North" || location == "East" || location == "north" || location == "east")
        {
            total_value += A.Conversion(0); //keeps track of how much money was dispensed
        }
        else if (location == "South" || location == "West" || location == "south" || location == "west")
        {
            total_value += A.Conversion(1); //keeps track of how much money was dispensed
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

    std::cout<<std::endl<<"Total dollars given out: $"<<total_value<<std::endl; //output total amount dispensed
    std:: cout<< "Exiting..."<<std::endl;
    return 0;
}
