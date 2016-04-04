// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "PowerSwitch.h"
#include "ModularServer.h"
#include "EventController.h"
#include "Constants.h"
#include "Callbacks.h"

class Controller : public PowerSwitch
{
public:
  Controller();
  void setup();
  void update();
  ModularDevice::ModularServer& getModularServer();

  void saveState(int state);
  void recallState(int state);
  void getStatesArray(uint32_t states_array[]);
private:
  ModularDevice::ModularServer modular_server_;
  SavedVariable saved_variables_[constants::SAVED_VARIABLE_COUNT_MAX];
  ModularDevice::Parameter parameters_[constants::PARAMETER_COUNT_MAX];
  ModularDevice::Method methods_[constants::METHOD_COUNT_MAX];

  uint32_t states_array_[constants::STATE_COUNT];
};

extern Controller controller;

#endif
