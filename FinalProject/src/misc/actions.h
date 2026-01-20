#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include "dataSet.h"
#include "mainWindow.h"

void addVehicle(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);
void addCar(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);
void addTruck(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);


#endif
