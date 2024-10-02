//
//  BOP Port.h
//  PortMaster
//
//  Created by Mingze Lee on 2024/10/2.
//

#ifndef BOP_PORT_H_
#define BOP_PORT_H_
#include <iostream>


class Port
{
private:
    char * brand_;
    char style_[20];
    int bottles_;
public:
    Port(const char * br = "none", const char * st = "none", int bt = 0);
    Port(const Port &);
    virtual ~Port() { delete [] brand_; };
    Port & operator=(const Port &);
    Port & operator+=(int);
    Port & operator-=(int);
    int BottleCount() const;
    virtual void Show() const;
    friend std::ostream & operator<<(std::ostream &, const Port &);
};

class VintagePort : public Port
{
private:
    char * nickname_;
    int year_;
public:
    VintagePort();
    VintagePort(const char *, const char *, int, const char *, int);
    VintagePort(const VintagePort &);
    ~VintagePort() { delete [] nickname_; };
    VintagePort & operator=(const VintagePort &);
    void Show() const;
    friend std::ostream & operator<<(std::ostream &, const VintagePort &);
};


#endif
