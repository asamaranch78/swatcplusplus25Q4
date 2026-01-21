#ifndef __FILTER_ACTIONS_H__
#define __FILTER_ACTIONS_H__

#include "dataSet.h"
#include "mainWindow.h"

void filter(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);
void filterByYear(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);
void filterByManufacturer(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);
void filterByType(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin);

#endif
