#include "personstorage.h"

personStorage::personStorage(){
    runningDB = QSqlDatabase::database();
}
vector<cScientist> personStorage::execute(QSqlQuery query){
    vector<cScientist> list;
    query.exec();

    while(query.next()){//Býr til persónu og setur inn í vektor
       int id = query.value(0).toInt();
       string name = (query.value(1).toString()).toStdString();
       string a = (query.value(2).toString()).toStdString();
       char se = a[0];
       int yearB = query.value(3).toInt();
       int yearD = query.value(4).toInt();
       string fact = (query.value(5).toString()).toStdString();

       cScientist person(id,name,se,yearB,yearD,fact);
       list.push_back(person);
    }

    return list;
}
cScientist personStorage::getPerson(const int& id){
    QSqlQuery query = QSqlQuery(runningDB);
    query.prepare("SELECT * FROM Persons WHERE erased = 0 AND id = :id;");
    query.bindValue(":id",id);
    query.exec();

    cScientist p;
    while(query.next()){
       int id = query.value(0).toInt();
       string name = (query.value(1).toString()).toStdString();
       string a = (query.value(2).toString()).toStdString();
       char se = a[0];
       int yearB = query.value(3).toInt();
       int yearD = query.value(4).toInt();
       string fact = (query.value(5).toString()).toStdString();

       cScientist person(id,name,se,yearB,yearD,fact);
       p = person;
    }
    return p;
}

vector<cScientist> personStorage::sortByName(const bool& desc){
    QSqlQuery query;

    if(desc)
        query.prepare("SELECT * FROM Persons WHERE erased = 0 ORDER BY name COLLATE NOCASE DESC;");
    else
        query.prepare("SELECT * FROM Persons WHERE erased = 0 ORDER BY name COLLATE NOCASE;");

    vector<cScientist> list = execute(query);

    return list;
}

vector<cScientist> personStorage::sortBySex(const bool& desc){
   QSqlQuery query;

    if(desc){
        query.prepare("SELECT * FROM Persons WHERE erased = 0 "
                      "ORDER BY gender COLLATE NOCASE DESC, name COLLATE NOCASE ASC;");
        //Z-A
    }
    else{
        query.prepare("SELECT * FROM Persons WHERE erased = 0 "
                      "ORDER BY gender COLLATE NOCASE ,name COLLATE NOCASE;");
        //A-Z
    }

    vector<cScientist> list = execute(query);

    return list;
}

vector<cScientist>  personStorage::sortByYear(const bool& desc, const bool& bord){
    QSqlQuery query;

    if(desc){
        if(!bord){
            query.prepare("SELECT * FROM Persons WHERE erased = 0 "
                          "ORDER BY yob DESC, name COLLATE NOCASE ASC;");
        }
        else{
            query.prepare("SELECT * FROM Persons WHERE erased = 0 "
                          "ORDER BY yod DESC, name COLLATE NOCASE ASC;");
        }
    }
    else{
        if(!bord){
            query.prepare("SELECT * FROM Persons WHERE erased = 0"
                          " ORDER BY yob, name COLLATE NOCASE ASC;");
        }
        else{
            query.prepare("SELECT * FROM Persons WHERE erased = 0 "
                          "ORDER BY yod, name COLLATE NOCASE ASC;");
        }
    }
    vector<cScientist> list = execute(query);
    return list;
}

//Search list:
vector<cScientist> personStorage::searchByName(string input){

    QSqlQuery query = QSqlQuery(runningDB);
    query.prepare("SELECT * FROM Persons WHERE (erased = 0) "
                  "AND (name LIKE '%'||:input||'%' OR "
                  "yob LIKE '%'||:input||'%'OR "
                  "yod LIKE '%'||:input||'%')"
                  "ORDER BY name COLLATE NOCASE;");
    query.bindValue(":input",QString::fromStdString(input));
    vector<cScientist> list = execute(query);
    return list;
}

//Change list:
int personStorage::addPerson(const string& nam, const char& se, const int& yearB, const int& yearD, const string& fact){

    QSqlQuery query;
    query.prepare("INSERT INTO Persons (name, gender, yob, yod, fact) values(:nam, :se, :YoB, :YoD, :fact);");
    query.bindValue(":nam",QString::fromStdString(nam));
    query.bindValue(":se",QString(QChar(se)));
    query.bindValue(":YoB",QString::number(yearB));
    query.bindValue(":YoD",QString::number(yearD));
    query.bindValue(":fact",QString::fromStdString(fact));
    query.exec();

    QSqlQuery idFind("SELECT * FROM Persons WHERE id = (SELECT MAX(id)  FROM Persons);");

    idFind.exec();
    int id;
    while(idFind.next()){
        id = idFind.value(0).toInt();
    }
    return id;
}

void personStorage::editPerson(const int& id, const QString& value,const int& col){
    QSqlQuery query;
    string column;

    switch(col){
    case 2://Column 2: Name
        column = "name";
        break;
    case 3://Column 3: Sex
        column = "gender";
        break;
    case 4://Column 4: Year of birth
        column =  "yob";
        break;
    case 5://Column 5: Year of death
        column =  "yod";
        break;
    case 6://Column 6: Fun fact
        column =  "fact";
        break;
    }
    query.prepare(QString("UPDATE Persons SET %1 = :input WHERE id = :id;").arg(QString::fromStdString(column)));
    query.bindValue(":input", value);
    query.bindValue(":id",QString::number(id));
    query.exec();
}

void personStorage::deletePerson(const int& id){
    QSqlQuery query;
    query.prepare("UPDATE Persons SET erased = 1 WHERE id = :id;");
    query.bindValue(":id",QString::number(id));
    query.exec();
    //data.changeList(command);
}

//Connections:
    //List connections:
vector<Computer> personStorage::compsConnectedToPerson(const int& id){
    QSqlQuery a;
    a.prepare("SELECT * FROM Connections WHERE person_id = :id;");
    a.bindValue(":id",id);
    a.exec();
    vector<int> ids;
    while(a.next()){
        ids.push_back(a.value(1).toInt());
    }

    QSqlQuery b;
    vector<Computer> connected;
    for(unsigned int i = 0; i < ids.size();i++){
        b.prepare("SELECT * FROM Computers WHERE id = :id  ORDER BY name COLLATE NOCASE;");
        b.bindValue(":id",ids[i]);
        b.exec();
        while(b.next()){
            int id = b.value(0).toInt();
            string name = (b.value(1).toString()).toStdString();
            int year = b.value(2).toInt();
            string type = (b.value(3).toString()).toStdString();
            bool built = b.value(4).toInt();

            Computer comp(id,name,year,type,built);
            connected.push_back(comp);
        }
    }
    return connected;
}
vector<Computer> personStorage::compsNotConnectedToPerson(const int &id){
    vector <Computer> connected = compsConnectedToPerson(id);
    QSqlQuery b;

    vector <Computer> result;
    b.prepare("SELECT * FROM Computers ORDER BY name COLLATE NOCASE;");;
    b.exec();
    while(b.next()){
        int id = b.value(0).toInt();
        string name = (b.value(1).toString()).toStdString();
        int year = b.value(2).toInt();
        string type = (b.value(3).toString()).toStdString();
        bool built = b.value(4).toInt();
        Computer comp(id,name,year,type,built);
        result.push_back(comp);
    }
    for(unsigned int i = 0; i < result.size(); i++){
        for(unsigned int j = 0; j < connected.size();j++){
            if((result[i].getId()) == (connected[j].getId())){
                result.erase(result.begin()+i);
            }
        }
    }
    return result;
}

    //Edit connections:
void personStorage::addConnection(const int& personId, const int& computerId){
    QSqlQuery query;
    query.prepare("INSERT INTO Connections (person_id,computer_id) VALUES (:first,:second);");
    query.bindValue(":first",personId);
    query.bindValue(":second",computerId);
    query.exec();
}

void personStorage::deleteConnection(const int& personId, const int& computerId){
    QSqlQuery query;
    query.prepare("DELETE FROM Connections WHERE person_id = :first AND computer_id = :second;");
    query.bindValue(":first",personId);
    query.bindValue(":second",computerId);
    query.exec();
}

//Recycle bin:
vector<cScientist> personStorage::listErased(){
    QSqlQuery query;
    query.prepare("SELECT * FROM Persons WHERE erased = 1 ORDER BY name COLLATE NOCASE;");

    vector<cScientist> list = execute(query);

    return list;
}

void personStorage::restoreFromBin(const int& id){
    QSqlQuery query;
    query.prepare("UPDATE Persons SET erased = 0 WHERE id = :id;");
    query.bindValue(":id",QString::number(id));
    query.exec();
}

//Quit:
void personStorage::quit(){
    runningDB.close();
}
