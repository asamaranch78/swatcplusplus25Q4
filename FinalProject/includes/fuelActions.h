#ifndef __FUEL_ACTIONS_H__
#define __FUEL_ACTIONS_H__

#include "vehicle.h"
#include "mainWindow.h"

void fuelEffiCalc(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<MainWindow> mainWin);
void normalFuelEffiCalc(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<MainWindow> mainWin);
void electricFuelEffiCalc(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<MainWindow> mainWin);

#endif
