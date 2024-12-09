#include <tree.hpp>

namespace robot_tree
{
    TREE::TREE() {}

    TREE::~TREE() {}

    BT::NodeStatus TREE::isDoorOpen()
    {
        bool door_status = doorStatus();
        std::cout << "TREE door status: " << door_status << std::endl;

        if (door_status)
        {
            return BT::NodeStatus::SUCCESS;
        }
        else
        {
            return BT::NodeStatus::FAILURE;
        }
    }

    BT::NodeStatus TREE::openDoor()
    {
        bool door_opened = moveActuator();
        std::cout << "TREE door status: " << door_opened << std::endl;

        if (door_opened)
        {
            return BT::NodeStatus::SUCCESS;
        }
        else
        {
            return BT::NodeStatus::FAILURE;
        }
    }

    BT::NodeStatus TREE::enterRoom()
    {
        bool entered_room = moveRobot();
        std::cout << "TREE door status: " << entered_room << std::endl;

        if (entered_room)
        {
            return BT::NodeStatus::SUCCESS;
        }
        else
        {
            return BT::NodeStatus::FAILURE;
        }
    }
} // namespace robot_tree

int main(int argc, char **argv)
{
    BT::BehaviorTreeFactory factory;

    // robot_tree::TREE tree;
    std::shared_ptr<robot_tree::TREE> tree = std::make_shared<robot_tree::TREE>();
    tree->setDebug(true);
    tree->updateState(6);

    factory.registerSimpleAction(
        "OpenDoor",
        std::bind(&robot_tree::TREE::openDoor, tree));

    // factory.registerSimpleAction(
    //     "EnterRoom",
    //     std::bind(&robot_tree::TREE::enterRoom, tree));

    // factory.registerSimpleCondition(
    //     "IsDoorOpen",
    //     std::bind(&robot_tree::TREE::isDoorOpen, tree));

    // auto bt_tree = factory.createTreeFromFile("./../structure.xml");

    // bt_tree.tickWhileRunning();

  return 0;
}