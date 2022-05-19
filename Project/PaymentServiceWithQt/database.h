//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_DATABASE_H
#define CLIONPROJECTMODEL_DATABASE_H

#include <string>
#include "PaymentService.h"
#include "json.hpp"

void serializeToDb(const std::string& fileName, PaymentService* paymentService);

using json = nlohmann::json;

bool deserialize(const std::string& fileName, PaymentService* paymentService);

#endif //CLIONPROJECTMODEL_DATABASE_H
