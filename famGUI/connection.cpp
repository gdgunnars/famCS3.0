#include "connection.h"

connection::connection()
{

}
connection::connection(const int& pId, const int& cId){
    personId = pId;
    computerId = cId;
}

int getPersonId() const{
    return personId;
}

int getComputerId()const{
    return computerId;
}



