//
//  BOP Port.cpp
//  PortMaster
//
//  Created by Mingze Lee on 2024/10/2.
//

#include "BOP Port.h"
#include <iostream>
#include <cstring>

Port::Port(const char * br, const char * st, int bt)
{
    brand_ = new char [strlen(br) + 1];
    strcpy(brand_, br);
    strcpy(style_, st);
    bottles_ = bt;
}

Port::Port(const Port & myPort)
{
    brand_ = new char [strlen(myPort.brand_) + 1];
    strcpy(brand_, myPort.brand_);
    strcpy(style_, myPort.style_);
    bottles_ = myPort.bottles_;
}

Port & Port::operator=(const Port & myPort)
{
    if (this == & myPort)
        return * this;
    delete [] brand_;
    brand_ = new char [strlen(myPort.brand_) + 1];
    strcpy(brand_, myPort.brand_);
    strcpy(style_, myPort.style_);
    bottles_ = myPort.bottles_;
    return * this;
}

Port & Port::operator+= (int n)
{
    bottles_ += n;
    return * this;
}

Port & Port::operator-=(int n)
{
    if (bottles_ < n)
    {
        std::cout << "Not enough bottles.\n";
        return * this;
    }
    bottles_ -= n;
    return * this;
}

int Port::BottleCount() const
{
    return bottles_;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand_ << std::endl;
    std::cout << "Kind: " << style_ << std::endl;
    std::cout << "Bottles: " << bottles_ << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & myPort)
{
    os << myPort.brand_ << ", " << myPort.style_ << ", " << myPort.bottles_;
    return os;
}


VintagePort::VintagePort() : Port()
{
    nickname_ = new char [5];
    strcpy(nickname_, "none");
    year_ = 0;
}

VintagePort::VintagePort(const char * br, const char * st, int bt, const char * nn, int yr) : Port(br, st, bt)
{
    nickname_ = new char [strlen(nn) + 1];
    strcpy(nickname_, nn);
    year_ = yr;
}

VintagePort::VintagePort(const VintagePort & myVP) : Port(myVP)
{
    nickname_ = new char [strlen(myVP.nickname_) + 1];
    strcpy(nickname_, myVP.nickname_);
    year_ = myVP.year_;
}

VintagePort & VintagePort::operator=(const VintagePort & myVP)
{
    if (this == & myVP)
        return * this;
    Port::operator=(myVP);
    delete [] nickname_;
    nickname_ = new char [strlen(myVP.nickname_) + 1];
    strcpy(nickname_, myVP.nickname_);
    year_ = myVP.year_;
    return * this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname_ << std::endl;
    std::cout << "Year made: " << year_ << std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & myVP)
{
    operator<<(os, (const Port &) myVP);
    os << ", " << "\"" << myVP.nickname_ << "\", " << myVP.year_;
    return os;
}
