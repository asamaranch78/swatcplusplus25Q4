#ifndef __FORM_DRIVER_H__
#define __FORM_DRIVER_H__

#include <cstdint>
#include <string>
#include <form.h>
#include "window.h"

class FormDriver {
public:
    int16_t key;
    FORM *form;
    Window *window;

    FormDriver(Window *win);
    void createForm(FIELD *field[], std::string *msg[], size_t fieldSize);
    void handleFrom();
    void destroyForm();
};

#endif
