#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//struct used for storing fields of input date and weight
struct WeightMeasurement
{
    time_t date;
    double weight;
};
//function parses date input provided by user
time_t parse_date(const std::string &date_str)
{
    tm date_tm{ };
    std::stringstream date_stream(date_str);
    date_stream >> std::get_time(&date_tm, "%m/%d/%Y");
    return mktime(&date_tm);
}

int main()
{
    std::vector<WeightMeasurement> measurements;

    while (true)
    {
        std::string date_str;
        double input_weight;

        std::cout << "Enter date (mm/dd/yyyy) press 'q' to quit: ";
        getline(std::cin, date_str);

        if (date_str == "q") {
            break;
        }

        std::cout << "Enter weight: ";
        std::cin >> input_weight;  //use for y-axis in graph representation, will need iterate through

        std::cin.ignore();  // Ignore the newline character

        time_t date = parse_date(date_str); //need to use date_str in graph representation, iterating through and graphing each on x-axis
        WeightMeasurement measurement = {date, input_weight};
        measurements.push_back(measurement);
    }

    std::cout << "Date\tWeight" << std::endl; //headers
    //different for-loop, research it
    for (const auto& measurement : measurements)
    {
        //iterating through, outputting all user inputs for weight and date once they exit while(true) using "q"
        std::cout << std::put_time(localtime(&measurement.date), "%m/%d/%Y") << "\t"
             << measurement.weight << std::endl;
    }

    return 0;
}
