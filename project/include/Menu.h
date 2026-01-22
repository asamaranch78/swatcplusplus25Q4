#ifndef MENU_H
#define MENU_H

#include <string>
#include "Vehicle.h"   

class VehicleManager;

class Menu {
public:
    explicit Menu(VehicleManager& manager);

    // Ejecuta el loop principal del menú (bloqueante)
    void run();

private:
    // Acciones del menú
    void actionAddVehicle();
    void actionListVehicles() const;
    void actionSortVehicles();
    void actionFilterVehicles() const;
    void actionFindById() const;
    void actionSave() const;
    void actionLoad();

    // Helpers de input (robustos)
    static void clearCin();
    static int readInt(const std::string& prompt);
    static double readDouble(const std::string& prompt);
    static bool readBool01(const std::string& prompt);
    static std::string readLine(const std::string& prompt);

    // Helpers de dominio
    static int readVehicleType(); // 1=Car,2=Truck,3=Bike,4=Motorcycle
    static int readSortOption();
    static int readFilterOption();
    static int readFuelTypeOption();
    static int readMenuOption();
    static FuelType readFuelType();

private:
    VehicleManager& m_manager;
};

#endif // MENU_H
