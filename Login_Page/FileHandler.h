#pragma once
#include <string>
#include <vector>
#include "Users.h"
#include "Property.h"
#include <fstream>
#include <iostream>
#include"Global.h"
class FileHandler {
public:
    static void Save();
    static void Load();
};