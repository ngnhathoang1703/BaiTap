#pragma once
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "LibBase.h"

class NameException 
{
    string msg;
public:
    NameException(string mess) 
    {
        msg = mess;
    }
    string what() 
    {
        return msg;
    }
};

class DateException 
{
    string msg;
public:
    DateException(string mess) 
    {
        msg = mess;
    }
    string what() 
    {
        return msg;
    }
};

class PhoneException 
{
    string msg;
public:
    PhoneException(string mess) 
    {
        msg = mess;
    }
    string what() {
        return msg;
    }
};

class EmailException 
{
    string msg;
public:
    EmailException(string mess) 
    {
        msg = mess;
    }
    string what() 
    {
        return msg;
    }
};
class MyException 
{
    string msg;
public:
    MyException(string mess) 
    {
        msg = mess;
    }
    string what() 
    {
        return msg;
    }
};

#endif // !__EXCEPTION_H__
