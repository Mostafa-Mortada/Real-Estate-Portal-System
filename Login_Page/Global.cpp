#include "Global.h"

int Global::currId = -1;
Users Global::currUser;
int Global::inComp = 0;
int Global::company_balance = 0;

std::map<int , Users> Global::users;
std::list<Property> Global::properties;

std::string Global::toLowerCase(const std::string& s) {
    std::string res;
    for (char c : s) {
        res.push_back(std::tolower(c));
    }
    return res;
}

bool Global::isContain(std::string a, std::string b)
{
    std::string lowerStr = Global::toLowerCase(a);
    std::string lowerSub = Global::toLowerCase(b);
    return lowerStr.find(lowerSub) != std::string::npos;
}


std::queue<Property> Global::search(std::string location, std::string type, int area, int mnPrice, int mxPrice, int nmOfbedrooms, std::string ownerName)
{
    std::queue<Property>result;
    for (auto& p : Global::properties) {
        bool locationMatch = (location == "") || (isContain(p.getLocation(), location));

        bool typeMatch = (type == "") || (isContain(p.getType(), type));
        
        bool areaMatch = (area == -1) || (p.getArea() == area);
        
        bool priceMatch = (mnPrice == -1 || p.getPrice() >= mnPrice) &&
            (mxPrice == -1 || p.getPrice() <= mxPrice);
        
        bool bedroomsMatch = nmOfbedrooms == 0 || p.getNumBedrooms() == nmOfbedrooms;
        
        bool ownername = (ownerName == "") || (isContain(Global::users[p.getOwnerId()].getName() , ownerName));

        if (locationMatch && typeMatch && areaMatch && priceMatch && bedroomsMatch && ownername) {
            result.push(p);
        }
    }
    return result;
}

std::queue<Users> Global::search_users(std::string name, std::string email)
{
    std::queue<Users>result;
    if (name == "" and email == "") {
        for (auto u : Global::users) {
            result.push(u.second);
        }
        return result;
    }
    else if (name == "") {
        for (auto u : Global::users) {
            if (isContain(u.second.getEmail(), email))
                result.push(u.second);
        }
        return result;
    }
    else {
        for (auto u : Global::users) {
            if (isContain(u.second.getName(), name))
                result.push(u.second);
        }
        return result;
    }
}