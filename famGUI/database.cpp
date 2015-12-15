#include "database.h"

database::database(){

  db = QSqlDatabase::addDatabase("QSQLITE");
  QString databaseName = "../famCS.db";
  db.setDatabaseName(databaseName);
  db.open();

  if(db.isOpen()){
    QSqlQuery query = QSqlQuery(db);

    query.prepare("CREATE TABLE IF NOT EXISTS Persons("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name varchar,"
                "gender char,"
                "yob int,"
                "yod int,"
                "fact text,"
                "erased boolean DEFAULT 0);");
    query.exec();
    query.prepare("CREATE TABLE IF NOT EXISTS Computers("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name varchar,"
                " build_year int,"
                "type varchar,"
                "built boolean,"
                "erased int DEFAULT 0);");
    query.exec();
    query.prepare("CREATE TABLE IF NOT EXISTS Connections("
                "person_id int not null, "
                "computer_id int not null,"
                "PRIMARY KEY(person_id, computer_id),"
                "FOREIGN KEY(person_id) REFERENCES Persons(id),"
                "FOREIGN KEY(computer_id) REFERENCES Computers(id));");

    query.exec();
  }
}

void database::close(){

  db.close();
}
