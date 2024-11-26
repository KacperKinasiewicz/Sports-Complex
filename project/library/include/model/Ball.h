#ifndef COURTRENTAL_BALL_H
#define COURTRENTAL_BALL_H

#include "Equipment.h"

enum SegmentType {Football, Basketball, Volleyball};

class Ball : public Equipment {
private:
    SegmentType segment;

public:
    Ball();
    Ball(const std::string &pModel, int pBasePrice, const SegmentType &pSegment);
    ~Ball();

    virtual const std::string getInfo() const override;
    virtual const double getActualEquipmentPrice() const override;

    const std::string getSegmentType() const;
    const double getSegmentCost() const;
};

#endif //COURTRENTAL_BALL_H