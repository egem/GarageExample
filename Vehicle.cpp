#include "Vehicle.h"

Vehicle::Vehicle(
  VehicleType vehicleType,
  unsigned int height,
  unsigned int width
): vehicleType(vehicleType), height(height), width(width) {
  static int _id = 1;
  id = _id++;
}

Vehicle::~Vehicle() {}

int Vehicle::getId() const {
  return id;
}

VehicleType Vehicle::getVehicleType() const {
  return vehicleType;
}

unsigned int Vehicle::getHeight() const {
  return height;
}

unsigned int Vehicle::getWidth() const {
  return width;
}
