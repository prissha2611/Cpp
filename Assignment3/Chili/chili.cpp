#include    <iostream>
#include    <map>
#include    <string>
#include    <fstream>
#include    <sstream>

class Chili{
public:
    float size;
    Chili(std::string cup_size) //quantify the cup_size in terms of cups
    {
        if(cup_size == "Short" || cup_size == "short")
        {
            size = 1; //Short = 1 cup
        }
        else if(cup_size == "Tall" || cup_size == "tall")
        {
            size = 1.5; //Tall = 1.5 cup
        }
        else if(cup_size == "Grande" || cup_size == "grande")
        {
            size = 2; //Grande = 2 cup
        }
        else if(cup_size == "Venti" || cup_size == "venti")
        {
            size = 2.5; //Venti = 2.5 cup
        }
        else
        {
            size = 0; //If cup_size not available
        }
    }

    float Serve(float batch)
    {
        if(size == 0)
        {
            std::cout<<"Sorry cup size not available."<<std::endl;
        }
        else
        {
            batch = batch - size; //Batch decrease each time it is being served
            std::cout<<"Order served. ";
        }
        return batch;
    }

    void Check(float batch)
    {
        if(batch<2.5)
        {
            std::cout<<"Not much chili left!"<<std::endl<<std::endl;
        }
        else
        {
            std::cout<<"Still got lots of chili!"<<std::endl<<std::endl;
        }
    }
};

class Order{
public:
    std::map<std::string, std::string> customer_list;

    Order(std::string name, std::string filename)
    {
        std::ifstream inFile;
        std::string line;
        std::cout<<"-----Welcome "<<name<<"-----"<<std::endl;
        std::cout<<"Checking today's customers...";
        inFile.open(filename);
        if (!inFile.is_open())
        {
            std::cout<<"Unable to open file";
            exit(1);
        }
        while (!inFile.eof())
        {
            std::string    customer,cup_size,line_from_file;
            getline(inFile,line_from_file);
            std::stringstream    delimt_line(line_from_file);
            getline(delimt_line,customer,',');
            getline(delimt_line,cup_size,'\n');
            customer_list.insert({customer,cup_size}); //insert customer and order in map container
        }
        std::cout<<"done!"<<std::endl<<std::endl;
    }

    Chili Batches(std::string starbucks_cup)
    {
        return Chili(starbucks_cup);
    }

    void Break()
    {
        std::string answer;
        std::cout<<"Continue with orders or take a break (Continue or Break)? "<<std::endl;
        std::cin>>answer;
        std::cin.ignore();
        if(answer == "break" || answer == "Break")
        {
            std::cout<<"Ok. Press enter when you are done with your break. ";
            std::getline(std::cin,answer);
        }
    }
};

int main(int argc, char **argv)
{
    float answer,batch=0,i=1;
    std::string response;
    Order l1(argv[1],argv[2]);
    std::cout<<"How many batches of your famous chili are you making today? ";
    std::cin>>answer;
    std::cin.ignore();
    batch = answer*4; // Makes the initial batch of chillis and 1 batch = 4 cups
    std::cout<<std::endl<<"Starting Orders..."<<std::endl;

    for (std::map<std::string,std::string>::iterator it=l1.customer_list.begin(); it!=l1.customer_list.end(); it++)
    {
        std::cout<<std::endl<<"--Customer "<<i<<": "<<it->first<<"'s order is "<<it->second<<"."<<std::endl;

        if (batch < (l1.Batches(it->second).size))
        {
            std::cout<<"Sorry, not enough chili. Would you like to make another batch or quit? ";
            std::getline(std::cin,response);

            if(response == "quit" || response == "Quit") // Quit program
            {
                std::cout<<"Quiting program..."<<std::endl;
                break;
            }
            else if(response == "Yes" || response == "yes") // Makes more chili
            {
                std::cout<<"How many batches of your famous chilli are you making today? ";
                std::cin>>answer;
                std::cin.ignore();
                batch += answer*4;
                batch=l1.Batches(it->second).Serve(batch); // Serve chili
                i++; // Counter of customers
            }
            else // chili not enough to serve
            {
                std::cout<<"Order not served.";
                it--; //Do not move on to next customer
            }
        }
        else
        {
            batch=l1.Batches(it->second).Serve(batch); // Serve chili
            i++; // Counter of customers
        }
        l1.Batches(it->second).Check(batch); // Check remaining chili
        if(next(it) != l1.customer_list.end()) // Checks whether next iterator reach the end
        {
            l1.Break(); // To continue serving or take a break
        }
        else
        {
            std::cout<<"Order Complete!"<<std::endl;
        }
    }
    return 0;
}
