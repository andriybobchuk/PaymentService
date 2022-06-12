//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_DATABASE_H
#define CLIONPROJECTMODEL_DATABASE_H

#include <string>
#include "PaymentService.h"
#include "json.hpp"
#include "constants.h"

using json = nlohmann::json;

const std::string FILE_NAME = DATABASE_FILE;

void serialize();

bool deserialize();




#endif //CLIONPROJECTMODEL_DATABASE_H
