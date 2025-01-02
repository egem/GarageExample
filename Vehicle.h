#pragma once

#include <iostream>
#include "VehicleType.enum.h"
#include "Types.h"

class Vehicle {
  private:
    Meter height, width;
    int id;
    VehicleType vehicleType;

  protected:
    explicit Vehicle(
      VehicleType vehicleType,
      Meter height,
      Meter width
    );

  public:
    virtual ~Vehicle();

    int getId() const;

    VehicleType getVehicleType() const;

    Meter getHeight() const;

    Meter getWidth() const;
};
