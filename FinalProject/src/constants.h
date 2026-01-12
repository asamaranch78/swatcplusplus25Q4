#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <memory>
#include "dataSet.h"

#define WIDE_GAP 15
#define GAP 10
#define SHORT_GAP 3

#define SCREEN_WIDTH 160

#define MAIN_COLOR 1
#define MENU_COLOR 2
#define SELECTED_COLOR 3

#define HEARDER_LINE 1
#define MENU_OFFSET 2
#define DATA_OFFSET 2
#define SEP_OFFSET MENU_OFFSET + 1

#define MANUFACTURER_COL SHORT_GAP
#define MODEL_COL MANUFACTURER_COL + WIDE_GAP
#define YEAR_COL  MODEL_COL + GAP
#define WEIGHT_COL YEAR_COL + GAP
#define FUEL_EFFI_COL WEIGHT_COL + WIDE_GAP
#define FUEL_TYPE_COL FUEL_EFFI_COL + WIDE_GAP
#define TYPE_COL FUEL_TYPE_COL + WIDE_GAP
#define SPECIAL_COL TYPE_COL + WIDE_GAP

extern void initData(std::shared_ptr<DataSet> data);

#endif
