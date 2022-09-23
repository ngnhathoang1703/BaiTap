#pragma once
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "LibBase.h"

class NameException : public exception
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

class DateException : public exception
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

class PhoneException : public exception
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

#endif // !__EXCEPTION_H__
