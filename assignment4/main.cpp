//Ryan Luo
//Assignment 4

#include <iostream>
#include <string>
#include "CovidDB.h"
#include <fstream>
#include <sstream>


const std::string FILE_NAME = "WHO-COVID-data.csv";

void readCSV(CovidDb& db, const std::string& filename);

int main() {
    
    CovidDb covidDb;
    bool quit = false;
    
    int input, cases, deaths;
    std::string date, country;
    
    while (!quit) {
        std::cout << std::endl << std::endl << "Covid Tracker" << std::endl;
        std::cout << "Please choose the operation you want:" << std::endl;
        std::cout << "1. Create the initial hash table" << std::endl;
        std::cout << "2. Add a new data entry" << std::endl;
        std::cout << "3. Get a data entry" << std::endl;
        std::cout << "4. Remove a data entry" << std::endl;
        std::cout << "5. Display hash table" << std::endl;
        std::cout << "0. Quit the system" << std::endl;
        std::cout << "Enter your choice: ";
        
        
        std::cin >> input;
        
        switch (input) {
            case 1: {
                //Initial hashtable
                readCSV(covidDb, FILE_NAME);
                std::cout << "Initial Hashtable Created" << std::endl;
                break;
            }
            case 2: {
                // Add entry
                std::cout << "Please enter the data entry in the following order: " << std::endl;
                std::cout << "date(m/d/yy) country cases deaths" << std::endl;
                std::cin >> date >> country >> cases >> deaths;
                DataEntry* entry = new DataEntry(date, country, cases, deaths);
                bool added = covidDb.add(entry);
                if (added) {
                    std::cout << "Data entry added successfully." << std::endl;
                } else {
                    std::cout << "Failed to add data entry. Check that the date is newer than the existing data for that country." << std::endl;
                }
                break;
            }
            case 3: {
                //Print specific entry
                std::cout << "Enter name of country: " << std::endl;
                std::cin.ignore();
                getline(std::cin, country);
                DataEntry* entry = covidDb.get(country);

                if(entry == nullptr) {
                    std::cout << "No entry found for " << country;
                    break;
                }
                
                std::cout << "Data entry for " << country << ":" << std::endl;
                std::cout << "Date: " << entry->getDate() << std::endl;
                std::cout << "Total cases: " << entry->getCases() << std::endl;
                std::cout << "Cumulative deaths: " << entry->getDeaths() << std::endl;
                break;
            }
            case 4: {
                // remove data entry
                std::cout << "Enter name of country to remove: ";
                std::cin.ignore();
                getline(std::cin, country);
                covidDb.remove(country);
                std::cout << "Data entry for " << country << " has been removed " << std::endl;
                break;
            }
            case 5: {
                //display hash table
                covidDb.displayTable();
                break;
            }
            case 0: {
                quit = true;
                return 0;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    return 0;
}

void readCSV(CovidDb& db, const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }
    std::string line;
    // ignore first line (header)
    std::getline(infile, line);
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string date, country;
        int cases, deaths;
        // extract date, country, cases, and deaths from line
        std::getline(ss, date, ',');
        std::getline(ss, country, ',');
        ss >> cases;
        ss.ignore();
        ss >> deaths;
        // store/modify hash table entry
        DataEntry* entry = new DataEntry(date, country, cases, deaths);
        db.add(entry);
    }   
}
