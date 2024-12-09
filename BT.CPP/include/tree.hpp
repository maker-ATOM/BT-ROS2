#pragma once

//
#include <chrono>
#include <iostream>
#include <memory>
#include <robot.hpp>
#include <string>

#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"

namespace robot_tree
{
class TREE : public robot::ROBOT
{
public:
  /**
     * @brief Construct a new TREE object
     *
     */
  TREE();

  /**
     * @brief Destroy the TREE object
     *
     */
  ~TREE();

  /**
     * @brief Check if door is open
     *
     * @return BT::nodeStatus
     */
  BT::NodeStatus isDoorOpen();

  /**
     * @brief Open the Door
     *
     * @return BT::nodeStatus
     */
  BT::NodeStatus openDoor();

  /**
     * @brief Enter Room
     *
     * @return BT::nodeStatus
     */
  BT::NodeStatus enterRoom();

private:
};
}  // namespace robot_tree