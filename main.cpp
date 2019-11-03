//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include "RandomHelper.h"
#include "Transaction.h"
#include "TransactionTestGenerator.h"
#include "Data/Database.h"
#include <SQLiteCpp/SQLiteCpp.h>


int main(int argc, char *argv[]){

    // Using SQLITE_VERSION would require #include <sqlite3.h> which we want to avoid: use SQLite::VERSION if possible.
//  std::cout << "SQlite3 version " << SQLITE_VERSION << std::endl;
    std::cout << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << std::endl;
    std::cout << "SQliteC++ version " << SQLITECPP_VERSION << std::endl;


    ////////////////////////////////////////////////////////////////////////////
    // Simple batch queries example :
    try
    {
        // Open a database file in create/write mode
        SQLite::Database    db("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
        std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully\n";

        // Create a new table with an explicit "id" column aliasing the underlying rowid
        db.exec("DROP TABLE IF EXISTS test");
        db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

        // first row
        int nb = db.exec("INSERT INTO test VALUES (NULL, \"test\")");
        std::cout << "INSERT INTO test VALUES (NULL, \"test\")\", returned " << nb << std::endl;

        // second row
        nb = db.exec("INSERT INTO test VALUES (NULL, \"second\")");
        std::cout << "INSERT INTO test VALUES (NULL, \"second\")\", returned " << nb << std::endl;

        // update the second row
        nb = db.exec("UPDATE test SET value=\"second-updated\" WHERE id='2'");
        std::cout << "UPDATE test SET value=\"second-updated\" WHERE id='2', returned " << nb << std::endl;

        // Check the results : expect two row of result
        SQLite::Statement   query(db, "SELECT * FROM test");
        std::cout << "SELECT * FROM test :\n";
        while (query.executeStep())
        {
            std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1) << "\")\n";
        }

        db.exec("DROP TABLE test");
    }
    catch (std::exception& e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        return EXIT_FAILURE; // unexpected error : exit the example program
    }
    remove("test.db3");

    std::cout << "everything ok, quitting\n";


    Database db;

    db.createTransactionTable();


    std::cout << "Generating new transactions" << std::endl;
//    Transaction * t1 = TransactionTestGenerator::generate();
//    std::cout << (*t1) << std::endl;
    for( int i =0; i < 10; i++) {
        Transaction * t1 = TransactionTestGenerator::generate();
//        std::cout <<  (*t1) << std::endl;
        db.insertTransaction(*t1);
    }

    std::vector<Transaction> transactions = db.getAllTransactions();
    db.emptyTransactiontable();
    db.deleteTransactionTable();
    for( Transaction t : transactions) {
        std::cout << t << std::endl;
    }
    return 0;
}