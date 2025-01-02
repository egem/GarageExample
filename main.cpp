#include <iostream>

#include "Garage.h"
#include "Car.h"

int main() {
  try
  {
    Garage garage(2);
    Car car1(10, 10);
    Car car2(20, 10);

    std::string ticket1 = garage.park(car1);
    std::string ticket2 = garage.park(car2);

    garage.takeVehicleOut(ticket1);
    garage.takeVehicleOut(ticket2);
  }
  catch(const ParkingFullError& e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "Please increase parking capacity" << std::endl;
  }
  catch(const ParkingIdNotFound& e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "Parking id not found" << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
