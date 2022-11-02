//
// Created by USER on 21.05.2022.
//

#ifndef INC_3_2_BASED_H
#define INC_3_2_BASED_H
#include <vector>
#include <string>

using namespace std;

class Based {
    string name;
    Based* parent;
    int state = 0;
    vector<Based*> children;
public:
    Based(string name,Based* parent);
    void SetName(string str);
    string GetName();
    void SetParent(Based* parnt);
    Based* GetParent();
    void Print(int stage);
    Based* Find(const string& your_name);
    Based* Search(Based* prnt, const string& moniker);
    void SetState(int readiness);
    int GetState() const;
    void State(int lvl);
    Based* FindByPath(string path);
};

#endif //INC_3_2_BASED_H
