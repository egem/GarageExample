#include "Garage.h"

const char* ParkingFullError::what() const _NOEXCEPT {
  return "Parking is full";
}

ParkingIdNotFound::ParkingIdNotFound(const std::string& parkingId): parkingId(parkingId) {}

const char* ParkingIdNotFound::what() const _NOEXCEPT {
  return "Parking id not found";
}

Garage::Garage(unsigned int capacity): capacity(capacity) {}

std::string Garage::createTicketId() const {
  static int i = 1;
  std::stringstream ss;
  ss << i++;

  return ss.str();
}

std::string Garage::park(const Vehicle& vehicle) {
  if (parkingInfoMap.size() >= capacity) {
    throw ParkingFullError();
  }

  std::string ticketId = createTicketId();

  parkingInfoMap[ticketId] = {
    vehicle.getVehicleType(),
    vehicle.getId(),
    "",
    ""
  };

  return ticketId;
}

int Garage::takeVehicleOut(const std::string& parkingId) {
  auto parkingInfoIterator = parkingInfoMap.find(parkingId);

  if (parkingInfoIterator == parkingInfoMap.end()) {
    throw ParkingIdNotFound(parkingId);
  }

  return parkingInfoIterator->second.vehicleId;
}
