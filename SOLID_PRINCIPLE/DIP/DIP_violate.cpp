#include <iostream>
#include <string>
using namespace std;

class SqlDatabase
{ // low leve module
public:
    void saveToSql(string s)
    {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << s << "');" << endl;
    }
};

class MongoDBDatabase
{
public:
    void saveToMongo(string s)
    {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << s << "'})" << endl;
    }
};

class UserService
{
private:
    SqlDatabase sqlDb;       // Direct dependency on MySQL
    MongoDBDatabase mongoDb; // Direct dependency on MongoDB

public:
public:
    void storeUserToSQL(string user)
    {
        // MySQL-specific code
        sqlDb.saveToSql(user);
    }

    void storeUserToMongo(string user)
    {
        // MongoDB-specific code
        mongoDb.saveToMongo(user);
    }
};

// main method
int main()
{
    UserService *userService=new UserService();

    userService->storeUserToMongo("santu");
    userService->storeUserToSQL("Saikat");
    return 0;
}