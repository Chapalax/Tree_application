//
// Created by USER on 22.05.2022.
//

#ifndef INC_3_2_DERIVED5_H
#define INC_3_2_DERIVED5_H
#include <utility>

#include "Based.h"
class Derived5 : public Based{
public:
    Derived5(string name, Based* parent) : Based(std::move(name), parent){};
};


#endif //INC_3_2_DERIVED5_H
