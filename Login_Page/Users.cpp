#include "Users.h"
#include "Property.h"
#include "Global.h"
#include "Authentication.h"

Users::Users()
{

}

Users::Users(int id, bool isAdmin, int balance, std::string name, std::string email, std::string password, std::string phonenumber, bool frozen)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
    this->phoneNumber = phonenumber;
    this->isAdmin = isAdmin;
    this->frozen = frozen;
    this->balance = balance;
     
}
bool Users::getFrozen() {
    return this->frozen;
}
int Users::getBalance() {
    return this->balance;
}

bool Users::getAdmin() {
    return this->isAdmin;
}

int Users::getId()
{
    return id;
}

std::string Users::getName()
{
    return name;
}

std::string Users::getEmail() {
    return email;
}

std::string Users::getPassword()
{
    return password;
}

std::string Users::getPhoneNumber() {
    return phoneNumber;
}

std::string Users::to_string() {
    return "User ID: " + std::to_string(id) + "\n" +
        "Name: " + name + "\n" +
        "Email: " + email + "\n" +
        "Password: " + password + "\n" +
        "Phone Number: " + phoneNumber + '\n' +
        "Balance: " + std::to_string(balance) + '\n' + 
        "Is Frozen: " + std::to_string(frozen) + '\n' +
        "Is Admin: " + std::to_string(isAdmin);
}

void Users::setFrozen(bool freeze)
{
    this->frozen = freeze;
}

void Users::addProperty(std::string type, std::string location, int price, int bedrooms, double area , std::string description)
{
    int id = 0;
    for (auto p : Global::properties) {
        id = std::max(id, p.getId());
    }
    if (this->isAdmin) {
        Global::properties.push_back(Property(id + 1, type, location, price, Global::currId, 1, bedrooms, area, 0, description));
    }
    else if (!this->frozen) {

        Global::properties.push_back(Property(id + 1 , type , location , price , Global::currId, 0 , bedrooms , area , 0 , description));
    }
}

bool Users::removeProperty(int propertyID)
{
    if (!this->frozen) {
        for (auto it = Global::properties.begin(); it != Global::properties.end(); ++it) {
            if ((it)->getId() == propertyID && ((it)->getOwnerId() == Global::currId || this->isAdmin)) {
                Global::properties.erase(it);
                return true;
            }
        }
    }
    return false;
}

void Users::editProperty(int proId, Property pro)
{
    if (this->isAdmin) {
        for (auto& p : Global::properties) {
            if (p.getId() == proId) {
                p = pro;
                break;
            }
        }
    }
}

void Users::addBalance(int balance)
{
    this->balance += balance;
}

int Users::buyProperty(int proId)
{
    if (!this->frozen) {
        for (auto& p : Global::properties) {
            if (p.getId() == proId) {
                if (this->balance >= p.getPrice() && p.getAvailability() == 1) {
                    if (p.getInComparison()) {
                        p.setInComparison(0);
                        Global::inComp--;
                    }
                    int i = p.getOwnerId();
                    //balance if owner is admin
                    if (Global::users[i].isAdmin) {
                        Global::company_balance += p.getPrice();
                        Global::users[Global::currId].addBalance(-p.getPrice());
                    }
                    
                    //balance if owner is normal user
                    else {
                        Global::users[i].addBalance(p.getPrice());
                        Global::users[Global::currId].addBalance(-p.getPrice());
                    }
                    ///
                    p.setOldId(i);
                    p.setOwnerId(Global::currId);
                    p.setAvailability(2);
                    return 0;
                }
                else return 2;
            }
        }
    }
    else return 1;
    return 0;
}

void Users::setAvailability(int proId , int Availability)
{
    if (this->isAdmin) {
        for (auto& p : Global::properties) {
            if (p.getId() == proId) {
                p.setAvailability(Availability);
            }
        }
    }
}

void Users::Moderate(int id, bool freezeFlag)
{
    if (this->isAdmin) {
        Global::users[id].setFrozen(freezeFlag);
    }
}

void Users::highLight_property(int proId, bool h)
{
    if (this->isAdmin) {
        for (auto& pro : Global::properties) {
            if (pro.getId() == proId) {
                pro.setHighlight(h);
            }
        }
    }
}

int Users::add_admin(std::string name, std::string email, std::string pass, std::string phone)
{
    if (this->isAdmin) {
        if (pass.length() < 8) {
            return 1;
        }
        int id = 0;
        for (auto u : Global::users) {
            id = std::max(id, u.second.getId());
            if (u.second.getEmail() == email) {
                return 2;
            }
        }
        Global::users[id + 1] = Users(id + 1, 1, 0, name, email, pass, phone, 0);
        return 0;
    }
    else return 3;
}

void Users::setName(std::string name) {
    this->name = name;
}
void Users::setEmail(std::string email) {
    this->email = email;
}
void Users::setPassword(std::string password)
{
    this->password = password;
}
void Users::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}