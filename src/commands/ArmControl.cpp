#include "commands/ArmControl.h"
#include "Robot.h"
#include "Constants.h"

ArmControl::ArmControl(bool Up) {
  this->Up = Up;
  requires(Robot::arm);
  this->priority = 1;
}

bool ArmControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void ArmControl::execute() {
  if (this->Up)
    Robot::arm->move(-KMaxMotorSpeed);
  else
    Robot::arm->move(KMaxMotorSpeed);
}

bool ArmControl::isFinished() {
  return true;
}

void ArmControl::end() {
  // Code that runs when isFinished() returns true.
}

void ArmControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
