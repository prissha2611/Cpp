#include <iostream>
#include <vector>
#include <string>
#include <map>

// Contains information of the rider //
class Rider{
    std::string rider_name;
    int height;

public:
    Rider()
    {}
    Rider(std::string name,int h)
    {
        rider_name = name;
        height = h;
    }
    Rider(int h)
    {
        height = h;
    }
    int get_height()
    {
        return  height;
    }
};

class ride{
    std::vector<Rider> line;
    Rider h;

public:
    ride()
    {}

    ride (int h)
    {
        this->h = h;
    }

    void add_line(Rider p) // checks whether the rider meets the minimum height reqirement to be added to the line
    {
        int min_height = h.get_height(); // contains the value of the minimum height of the ride chosen
        if(min_height <= p.get_height()) // the minimum height is compared with the rider's height
        {
            line.push_back(p);
            std::cout<<std::endl<<"Adding rider to line"<<std::endl<<std::endl;
        }
        else
        {
            std::cout<<std::endl<<"Sorry can't add rider - too short"<<std::endl;
        }
    }
};

class Amusement_park{
    int min_height;
    std::string ride_num;
    std::map<int,ride> rides;

public:
    Amusement_park(int num_rides)
    {
        std::cout<< "~~~ Amusement park information ~~~";
        for(int i=1;i<=num_rides;i++)
        {
            std::cout<<std::endl<< "Ride "<<i<<"- Enter minimum ride height and ride name:"<< std::endl;
            std::cin>>min_height>>ride_num;
            rides[i]=ride(min_height); // contains the minimum height for each ride
        }
    }
    ride get_ride (int num)
    {
        std::map<int,ride>::iterator it = rides.find(num);
        return it->second; // returns the minimum height of the ride interested
    }
};

int main()
{
    Rider r1("Yaris", 45);    //name, height in inches
    Rider r2(49);    //height in inches
    Amusement_park a1(3);    //3 is the number of rides in the amusement park
    a1.get_ride(1).add_line(r1);     //add a rider to the line of a ride
    Amusement_park a2(2);    //2 is the number of rides in the amusement park
    a2.get_ride(1).add_line(r2);    //add a rider to the line of a ride
    return 0;
}
