#include <robot.hpp>

namespace robot
{
ROBOT::ROBOT()
{
  door_open_ = false;
  actuator_moved_ = false;
  robot_moved_ = false;
  debug_ = false;
  state_ = 0;
}

ROBOT::~ROBOT()
{
  if (debug_) {
    std::cout << "\033[36m"
              << "ROBOT object destroyed! \033[00m" << std::endl;
  }
}

void ROBOT::setDebug(bool state)
{
  debug_ = state;
  if (debug_) {
    std::cout << "\033[36m"
              << "ROBOT debug enabled! \033[00m" << std::endl;
  }
}

void ROBOT::updateState(int state_number)
{
  state_ = state_number;
  if (debug_) {
    std::cout << "\033[36m"
              << "ROBOT state updated! \033[00m" << std::endl;
  }
}

bool ROBOT::doorStatus()
{
  door_open_ = static_cast<bool>((state_ >> 0) & 1);
  // if (debug_) {
  //   std::cout << "\033[36m"
  //             << "ROBOT state:" << door_open_ << "\033[00m" << std::endl;
  // }
  return door_open_;
}

bool ROBOT::moveActuator() { return static_cast<bool>((state_ >> 1) & 1); }

bool ROBOT::moveRobot()
{
  door_open_ = static_cast<bool>((state_ >> 2) & 1);
  return door_open_;
}
}  // namespace robot