#pragma once

#include "Vehicle.h"

class Car: public Vehicle {
  public:
    explicit Car(Meter height, Meter width);
};
