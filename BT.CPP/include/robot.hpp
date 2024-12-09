#pragma once

//
#include <iostream>
#include <memory>
#include <string>

namespace robot
{
class ROBOT
{
public:
  /**
     * @brief Construct a new ROBOT object
     * 
     */
  ROBOT();
  /**
         * @brief Destroy the ROBOT object
         * 
         */
  ~ROBOT();

  /**
         * @brief To print debug statements or not
         * 
         */
  void setDebug(bool state);

  /**
         * @brief Update robot state
         * 
         */
  void updateState(int state_number);

  /**
         * @brief Return status of door
         * 
         * @return true 
         * @return false 
         */
  bool doorStatus();

  /**
         * @brief Return if the actuator was moved to given pose
         * 
         * @return true 
         * @return false 
         */
  bool moveActuator();

  /**
         * @brief Return if the reached the given pose
         * 
         * @return true 
         * @return false 
         */
  bool moveRobot();

private:
  bool door_open_;
  bool actuator_moved_;
  bool robot_moved_;
  bool debug_;
  int state_;
};
}  // namespace robot