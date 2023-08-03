#include <iostream>
#include <sstream>
#include "CovidDB.h"

DataEntry::DataEntry() {
    date = "";
    country = "";
    c_cases = 0;
    c_deaths = 0;
}

DataEntry::DataEntry(std::string date, std::string country, int c_cases, int c_deaths){
    setDate(date);
    setCountry(country);
    setCases(c_cases);
    setDeaths(c_deaths);
}

void DataEntry::setDate(std::string date) {
    this->date = date;
}

void DataEntry::setCountry(std::string country) {
    this->country = country;
}

void DataEntry::setCases(int c_cases) {
    this->c_cases = c_cases;
}

void DataEntry::setDeaths(int c_deaths) {
    this->c_deaths = c_deaths;
}

std::string DataEntry::getCountry(){
    return country;
}

std::string DataEntry::getDate() {
    return date;
}

int DataEntry::getCases() {
    return c_cases;
}


int DataEntry::getDeaths() {
    return c_deaths;
}


int CovidDb::hash(std::string country) {
    int sum = 0;

    for(int i = 0; i < (int)country.length(); i ++) {
        char c = country[i];
        sum += (1+i) * (int)(c); 
    }
    return sum%17;
}

bool CovidDb::add(DataEntry* entry) {
    //find hash
    int index = hash(entry->getCountry());

    // resize dataTable if necessary
    if ((int)dataTable.size() <= index) {
        dataTable.resize(index+1);
    }
    //if vector is empty, add entry to vector
    if (dataTable[index].size() == 0) {
        dataTable[index].push_back(entry);
        return true;
    }
    
    //check if existing country exists
    for (int i = 0; i < (int)dataTable[index].size(); i++) {
        if (dataTable[index][i]->getCountry() == entry->getCountry()) {
            // if it does, add the entry and adjust the values
            if(compareDate(dataTable[index][i]->getDate(), entry->getDate())){
                calculate(entry->getDate(), entry->getCountry(), entry->getCases(), entry->getDeaths());
                return true;
            }
            else {
                return false;
            }
        }
    }
    dataTable[index].push_back(entry);
    return true;
}

void CovidDb::displayTable() {
    for (int i = 0; i < (int)dataTable.size(); i++) {
        std::cout << "Index " << i << ": ";
        if (dataTable[i].empty()) {
            std::cout << "Empty" << std::endl;
        } else {
            //nested for loop to print
            for (int j = 0; j < (int)dataTable[i].size(); j++) {
                std::cout << "[" << dataTable[i][j]->getCountry() << ", " << dataTable[i][j]->getDate()
                          << ", " << dataTable[i][j]->getCases() << ", " << dataTable[i][j]->getDeaths() << "] ";
            }
            std::cout << std::endl << std::endl;
        }
    }
}

void CovidDb::remove(std::string country) {
    // Find hash
    int index = hash(country);

    // If vector is empty, return
    if (dataTable[index].empty()) {
        return;
    }

    // Search for matching entry
    for (int i = 0; i < (int)dataTable[index].size(); i++) {
        if (dataTable[index][i]->getCountry() == country) {
            // Remove the entry and delete the object
            delete dataTable[index][i];
            dataTable[index].erase(dataTable[index].begin() + i);
            return;
        }
    }
}


void CovidDb::calculate(std::string date, std::string country, int cases, int deaths) {
    // Find the vector of entries for the given country
    std::vector<DataEntry*>& entries = dataTable[hash(country)];

    // Iterate over the entries to find the matching one
    for (int i = 0; i < (int)entries.size(); i++) {
        if (entries[i]->getCountry() == country) {
            // Create a new entry with the updated case and death counts
            DataEntry* newEntry = new DataEntry(date, country, entries[i]->getCases() + cases, entries[i]->getDeaths() + deaths);
            // Remove the old entry and add the new one
            delete entries[i];
            entries[i] = newEntry;
            return;
        }
    }

    // If no matching entry was found, create a new one and add it to the vector
    DataEntry* newEntry = new DataEntry(date, country, cases, deaths);
    entries.push_back(newEntry);
}



DataEntry* CovidDb::get(std::string country) {
    // Find hash
    int index = hash(country);

    // If vector is empty, return nullptr
    if (dataTable[index].empty()) {
        return nullptr;
    }

    // Search for matching entry
    for (int i = 0; i < (int)dataTable[index].size(); i++) {
        if (dataTable[index][i]->getCountry() == country) {
            return dataTable[index][i];
        }
    }

    // Entry not found, return nullptr
    return nullptr;
}


CovidDb::~CovidDb() {
    // iterate through table and delete all entries
    for (int i = 0; i < (int)dataTable.size(); i++) {
        for (int j = 0; j < (int)dataTable[i].size(); j++) {
            delete dataTable[i][j];
        }
        dataTable[i].clear();
    }
    dataTable.clear();
}

bool CovidDb::compareDate(std::string date1, std::string date2) {
    //create 2 std::istringstream objects to read the date strings
    std::istringstream iss1(date1), iss2(date2);
    std::string token;
    int month1, day1, year1, month2, day2, year2;

    //use getline() to read the tokens (month, day ,year)
    //then do it for both days
    
    //parse the first date
    std::getline(iss1, token, '/');
    month1 = std::stoi(token);
    std::getline(iss1, token, '/');
    day1 = std::stoi(token);
    std::getline(iss1, token);
    year1 = std::stoi(token);

    //parse the second date
    std::getline(iss2, token, '/');
    month2 = std::stoi(token);
    std::getline(iss2, token, '/');
    day2 = std::stoi(token);
    std::getline(iss2, token);
    year2 = std::stoi(token);

    //compare the dates
    //return true if year is earlier than second
    if (year1 < year2) {
        return true;
    } else if (year1 > year2) {
        return false;
    //if years are the same, we compare the months
    } else if (month1 < month2) {
        return true;
    } else if (month1 > month2) {
        return false;
    //and if months are the same we compare the days to see whch one is earlier
    } else if (day1 < day2) {
        return true;
    } else {
        return false;
    }
}

