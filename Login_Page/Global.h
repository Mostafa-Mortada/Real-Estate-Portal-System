#pragma once
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include "Property.h"
#include "Users.h"

class Global
{
public:
    // Global attributes
    static int currId; // Stores the ID of the currently signed-in user
    static Users currUser;
    static int inComp;
    static int company_balance;

    static std::map<int, Users> users;
    static std::list<Property> properties;
    // Global functions
    static std::string toLowerCase(const std::string& s); // for searching
	static bool isContain(std::string a, std::string b);


   static std::queue<Property>search(std::string location, std::string type , int area , int mnPrice , int mxPrice , int nmOfbedrooms , std::string ownerName = "");
   static std::queue<Users>search_users(std::string name, std::string email);
};
