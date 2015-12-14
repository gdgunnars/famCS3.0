#include "computerstorage.h"

computerStorage::computerStorage()
{
  runningDB = QSqlDatabase::database();
}
vector<Computer> computerStorage::execute(QSqlQuery query){
    vector<Computer> list;
    query.exec();
    while(query.next()){//Býr til tölvu og setur inn í vektor
       int id = query.value(0).toInt();
       string name = (query.value(1).toString()).toStdString();
       int year = query.value(2).toInt();
       string type = (query.value(3).toString()).toStdString();
       bool built = query.value(4).toInt();


       Computer comp(id,name,year,type,built);
       list.push_back(comp);
    }

    return list;
}
Computer computerStorage::getComputer(const int& id){
    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE erased = 0 AND id = :id");
    query.bindValue(":id",id);
    query.exec();

    Computer comp;
    while(query.next()){//Býr til tölvu og setur inn í vektor
       int id = query.value(0).toInt();
       string name = (query.value(1).toString()).toStdString();
       int year = query.value(2).toInt();
       string type = (query.value(3).toString()).toStdString();
       bool built = query.value(4).toInt();
       Computer c(id,name,year,type,built);
       comp = c;
    }
    return comp;
}

//Show list:
vector<Computer> computerStorage::sortByName(const bool& desc){
    QSqlQuery query = QSqlQuery(runningDB);

    if(desc)
        query.prepare("SELECT * FROM Computers WHERE erased = 0 ORDER BY name COLLATE NOCASE DESC;");
    else
        query.prepare("SELECT * FROM Computers WHERE erased = 0 ORDER BY name COLLATE NOCASE ASC;");

    vector<Computer> list = execute(query);
    return list;

}

vector<Computer> computerStorage::sortByYear(const bool& desc){
    QSqlQuery query = QSqlQuery(runningDB);
    if(desc){
        query.prepare("SELECT * FROM Computers "
                      "WHERE erased = 0 ORDER BY "
                      "build_year DESC, name COLLATE NOCASE ASC;");
    }
    else{
        query.prepare("SELECT * FROM Computers "
                      "WHERE erased = 0 ORDER BY "
                      "build_year, name COLLATE NOCASE ASC;");
    }
    vector<Computer> list = execute(query);
    return list;
}

vector<Computer> computerStorage::sortByType(const bool& desc){
    QSqlQuery query = QSqlQuery(runningDB);
    if(desc){
        query.prepare("SELECT * FROM Computers "
                      "WHERE erased = 0 ORDER BY "
                      "type COLLATE NOCASE DESC, name COLLATE NOCASE ASC;");
    }
    else{
        query.prepare("SELECT * FROM Computers "
                      "WHERE erased = 0 ORDER "
                      "BY type COLLATE NOCASE, name COLLATE NOCASE ASC;");
    }
    vector<Computer> list = execute(query);
    return list;
}

vector<Computer> computerStorage::sortByBuild(const bool& desc){
    QSqlQuery query = QSqlQuery(runningDB);
    if(desc){
        query.prepare("SELECT * FROM Computers WHERE erased = 0 ORDER BY built DESC, name COLLATE NOCASE ASC;");
    }
    else{
        query.prepare("SELECT * FROM Computers WHERE erased = 0 ORDER BY built, name COLLATE NOCASE ASC;");
    }
    vector<Computer> list = execute(query);
    return list;
}

//Search list:
vector<Computer> computerStorage::searchByName(string input){
    QSqlQuery query = QSqlQuery(runningDB);

    query.prepare("SELECT * FROM Computers WHERE (erased = 0) "
                  "AND (name LIKE '%'||:input||'%'OR "
                  "build_year LIKE '%'||:input||'%'OR "
                  "type LIKE '%'||:input||'%') "
                  "ORDER BY name COLLATE NOCASE ASC;");
    query.bindValue(":input",QString::fromStdString(input));
    vector<Computer> list = execute(query);
    return list;
}

//Change list:
int computerStorage::addComputer(const string& nam, const int& yea, const string& typ, const bool& buil){

    QSqlQuery query = QSqlQuery(runningDB);
    query.prepare("INSERT INTO Computers (name, build_year, type, built) values(:nam, :year, :type, :build);");
    query.bindValue(":nam",QString::fromStdString(nam));
    query.bindValue(":year",QString::number(yea));
    query.bindValue(":type",QString::fromStdString(typ));
    query.bindValue(":build",QString::number(buil));
    query.exec();

    QSqlQuery idFind("SELECT * FROM Computers WHERE erased = 0 AND id = (SELECT MAX(id)  FROM Computers);");


    idFind.exec();
    int id;
    while(idFind.next()){
        id = idFind.value(0).toInt();
    }
    return id;

}

void computerStorage::editComputer(const int& id, const QString& value,const int& col){
    QSqlQuery query = QSqlQuery(runningDB);
    string column;

    switch(col){
    case 2://Column 2: Name
        column = "name";
        break;
    case 3://Column 3: Build year
        column = "build_year";
        break;
    case 4://Column 4: Type
        column = "type";
        break;
    case 5://Column 5: Built or not
        column = "built";
        break;
    }
    query.prepare(QString("UPDATE Computers SET %1 = :input WHERE id = :id;").arg(QString::fromStdString(column)));
    query.bindValue(":input", value);
    query.bindValue(":id",QString::number(id));
    query.exec();
}

void computerStorage::deleteComputer(const int& id){
    QSqlQuery query;
    query.prepare("UPDATE Computers SET erased = 1 WHERE id = :id;");
    query.bindValue(":id",QString::number(id));
    query.exec();
}

//Connections:
    //List connections:
vector<cScientist> computerStorage::persConnectedToComp(const int& id){
    QSqlQuery a;
    a.prepare("SELECT * FROM Connections WHERE computer_id = :id;");
    a.bindValue(":id",id);
    a.exec();
    vector<int> ids;
    while(a.next()){
        ids.push_back(a.value(0).toInt());
    }


    QSqlQuery b;
    vector<cScientist> connected;
    for(unsigned int i = 0; i < ids.size();i++){
      b.prepare("SELECT * FROM Persons WHERE id = :id ORDER BY name COLLATE NOCASE;");
      b.bindValue(":id",ids[i]);
      b.exec();
      while(b.next()){
        int id = b.value(0).toInt();
        string name = (b.value(1).toString()).toStdString();
        string a = (b.value(2).toString()).toStdString();
        char se = a[0];
        int yearB = b.value(3).toInt();
        int yearD = b.value(4).toInt();
        string fact = (b.value(5).toString()).toStdString();

        cScientist person(id,name,se,yearB,yearD,fact);
        connected.push_back(person);
      }
    }
    return connected;
}

vector<cScientist> computerStorage::persNotConnectedToComp(const int &id)
{
    QSqlQuery a;
    a.prepare("select DISTINCT P.id "
              "from Persons AS P, Connections "
              "ON P.id NOT IN ("
              "select Persons.id "
              "from Persons INNER JOIN Connections "
              "ON Persons.id = Connections.person_id "
              "AND Connections.computer_id = :id) ORDER BY name COLLATE NOCASE;");
    a.bindValue(":id",id);
    a.exec();
    vector <int> ids;
    while(a.next()){
        ids.push_back(a.value(0).toInt());
    }

    QSqlQuery b;
    vector<cScientist> notConnected;
    for(unsigned int i = 0; i < ids.size();i++){
      b.prepare("SELECT * FROM Persons WHERE id = :id ORDER BY name COLLATE NOCASE;");
      b.bindValue(":id",ids[i]);
      b.exec();
      while(b.next()){
        int id = b.value(0).toInt();
        string name = (b.value(1).toString()).toStdString();
        string a = (b.value(2).toString()).toStdString();
        char se = a[0];
        int yearB = b.value(3).toInt();
        int yearD = b.value(4).toInt();
        string fact = (b.value(5).toString()).toStdString();

        cScientist person(id,name,se,yearB,yearD,fact);
        notConnected.push_back(person);
      }
    }
    return notConnected;
}
    //Edit connections:
void computerStorage::addConnection(const int& computerId, const int& personId){
    QSqlQuery query;
    query.prepare("INSERT INTO Connections (person_id,computer_id) VALUES (:first,:second);");
    query.bindValue(":first",personId);
    query.bindValue(":second",computerId);
    query.exec();
}

void computerStorage::deleteConnection(const int& computerId, const int& personId){
    QSqlQuery query;
    query.prepare("DELETE FROM Connections WHERE computer_id = :first AND person_id = :second;");
    query.bindValue(":first",computerId);
    query.bindValue(":second",personId);
    query.exec();
}
vector<Computer> computerStorage::listErased(){
    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE erased = 1 ORDER BY name COLLATE NOCASE;");

    vector<Computer> list = execute(query);

    return list;
}
void computerStorage::restoreFromBin(const int& id){
    QSqlQuery query;
    query.prepare("UPDATE Computers SET erased = 0 WHERE id = :id;");
    query.bindValue(":id",QString::number(id));
    query.exec();
}

