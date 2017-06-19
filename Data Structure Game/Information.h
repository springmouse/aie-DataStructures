#pragma once

#define INFOMATION Information::GetInstanceOfInfo()

class Information
{
public:

    static Information * GetInstanceOfInfo();

    void pushInfo(int ID) { pushID = ID; push = true; };

    bool quit = false;
    bool push = false;
    bool pop = false;

    int pushID = 0;

private:
    Information();
    ~Information();
};

