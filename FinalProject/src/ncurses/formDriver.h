#ifndef __FORM_DRIVER_H__
#define __FORM_DRIVER_H__

#include <cstdint>
#include <string>
#include <vector>
#include <form.h>

class FormDriver {
public:
    int16_t key;
    FORM *form;
    WINDOW *window;

    FormDriver(WINDOW* win);
    void createForm(FIELD *field[], std::vector<std::string> msg);
    void handleFrom();
    void destroyForm();
};

#endif
