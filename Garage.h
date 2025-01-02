#pragma once

#include <iostream>
#include <map>
#include <sstream>

#include "Vehicle.h"

struct ParkingInfo {
  VehicleType vehicleType;
  int vehicleId;
  std::string ownerName, ownerSurname;
};

class ParkingFullError: public std::exception {
  public:
    const char* what() const _NOEXCEPT;
};

class ParkingIdNotFound: public std::exception {
  private:
    const std::string parkingId;

  public:
    explicit ParkingIdNotFound(const std::string& parkingId);

    const char* what() const _NOEXCEPT;
};

class Garage {
  private:
    std::map<std::string, ParkingInfo> parkingInfoMap;
    unsigned int capacity;

    std::string createTicketId() const;

  public:
    Garage() = default;
    explicit Garage(unsigned int capacity);

    std::string park(const Vehicle& vehicle);
    int takeVehicleOut(const std::string& parkingId);
};
