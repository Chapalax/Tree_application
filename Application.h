//
// Created by USER on 21.05.2022.
//

#ifndef INC_3_2_APPLICATION_H
#define INC_3_2_APPLICATION_H


#include "Based.h"

class Application : public Based {
    string exception;
public:
    Application() : Based("", nullptr){};
    void Build();
    int Start();
};


#endif //INC_3_2_APPLICATION_H
