//
// Created by USER on 22.05.2022.
//

#ifndef INC_3_2_DERIVED4_H
#define INC_3_2_DERIVED4_H
#include <utility>

#include "Based.h"
class Derived4 : public Based{
public:
    Derived4(string name, Based* parent) : Based(std::move(name), parent){};
};

#endif //INC_3_2_DERIVED4_H
