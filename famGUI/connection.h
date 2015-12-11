#ifndef CONNECTION_H
#define CONNECTION_H


class connection
{
public:

    //Constructors:
    connection();
    connection(const int& pId,const int& cId);

    //Get functions:
    int getPersonId() const;
    int getComputerId()const;
private:

    //Private variables:
    int personId;
    int computerId;
};

#endif // CONNECTION_H
