#ifndef COURTRENTAL_CLIENTTYPE_H
#define COURTRENTAL_CLIENTTYPE_H

#include "typedefs.h"

class ClientType {
public:
    virtual ~ClientType() = 0;
    virtual const int getMaxCourts() const = 0;
    virtual const double applyDiscount(double pPrice) const = 0;
    virtual const std::string getTypeInfo() const = 0;
};

class Default : public ClientType {
public:
    const int getMaxCourts() const override;
    const double applyDiscount(double pPrice) const override;
    const std::string getTypeInfo() const override;
};

class FitCarnet : public ClientType {
public:
    const int getMaxCourts() const override;
    const double applyDiscount(double pPrice) const override;
    const std::string getTypeInfo() const override;
};

class Patron : public ClientType {
public:
    const int getMaxCourts() const override;
    const double applyDiscount(double pPrice) const override;
    const std::string getTypeInfo() const override;
};

class Trainer : public ClientType {
public:
    const int getMaxCourts() const override;
    const double applyDiscount(double pPrice) const override;
    const std::string getTypeInfo() const override;
};

#endif //COURTRENTAL_CLIENTTYPE_H