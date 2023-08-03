#include <iostream>
#include <sstream>
#include "CovidDB.cpp"
#include <cassert>
void testCovidDb() {
    // create CovidDb object
    CovidDb db;

    // create DataEntry objects to add to CovidDb
    DataEntry* entry1 = new DataEntry("5/1/21", "USA", 1000000, 20000);
    DataEntry* entry2 = new DataEntry("5/1/21", "India", 2000000, 30000);
    DataEntry* entry3 = new DataEntry("5/1/21", "Brazil", 500000, 15000);

    // test add() method
    assert(db.add(entry1));
    assert(db.add(entry2));
    assert(db.add(entry3));
    assert(!db.add(entry1)); // entry1 should already exist, so adding again should return false

    // test get() method
    assert(db.get("USA") == entry1);
    assert(db.get("India") == entry2);
    assert(db.get("Brazil") == entry3);
    assert(db.get("China") == nullptr); // China should not exist in the database

    // test remove() method
    db.remove("USA");
    assert(db.get("USA") == nullptr); // entry1 should have been removed
    db.remove("India");
    assert(db.get("India") == nullptr); // entry2 should have been removed
    db.remove("Brazil");
    assert(db.get("Brazil") == nullptr); // entry3 should have been removed
    db.remove("China"); // should not throw an error, since China is not in the database
}



int main() {
    testCovidDb();
}