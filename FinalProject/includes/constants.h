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
#define ERROR_COLOR 4

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

#define FORM_START 2
#define FORM_SPACE 2
#define FORM_WIDTH WIDE_GAP
#define FORM_HEIGHT 1
#define FORM_TEST_COL 10
#define FORM_COL FORM_TEST_COL + WIDE_GAP
#define FORM_WIN_WIDTH FORM_COL + WIDE_GAP + GAP
#define NO_OFF_SCREEN 0
#define NO_BUFFERS 0

#define MAX_FIELDS 10

//Indexes on fields array for common data
#define MANUFACTURER_INDEX 0
#define MODEL_INDEX 1
#define YEAR_INDEX 2
#define WEIGHT_INDEX 3
#define EFFICIENCY_INDEX 4

//Indexes on fields array for car data
#define DOORS_INDEX 5
#define TRUNK_INDEX 6
//Indexes on fields array for truck  data
#define AXLE_INDEX 5
#define LOAD_INDEX 6


extern void initData(std::shared_ptr<DataSet> data);

#endif
