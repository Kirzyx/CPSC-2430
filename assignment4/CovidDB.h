#include <iostream>
#include <string>
#include <vector>

class DataEntry{
    private: 
        std::string date;
        std::string country;
        int c_cases;
        int c_deaths;
    public:
        DataEntry();
        DataEntry(std::string date, std::string country, int c_cases, int c_deaths);
        void setDate(std::string date);
        void setCountry(std::string country);
        void setCases(int c_cases);
        void setDeaths(int c_deaths);
        std::string getDate();
        std::string getCountry();
        int getCases();
        int getDeaths();
        
};


class CovidDb {
    private:
        std::vector<std::vector<DataEntry*>> dataTable;
        
    public:
        DataEntry* get(std::string country);
        void displayTable();
        bool add(DataEntry* entry);
        void remove(std::string country);
        int hash(std::string country);
        void calculate(std::string date, std::string country, int cases, int deaths);
        ~CovidDb();
        bool compareDate(std::string date1, std::string date2);
       
};


