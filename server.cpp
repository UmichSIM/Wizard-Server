#include "CLI11.hpp"
#include <iostream>
#include <rpc/server.h>
#include <rpc/this_handler.h>

namespace Driver
{
// encode the drivers manually
const int PLAYER = 0;
const int WIZARD = 1;
int driver = Driver::PLAYER;

/**
 * @brief checks if driver is valid
 * @param driver: driver id
 **/
void check_driver(int driver)
{
    if (driver != Driver::PLAYER and driver != Driver::WIZARD)
        rpc::this_handler().respond_error("Error: Invalid Driver id");
}

/**
 * @brief set the current driver
 * @param driver: driver to be set
 **/
void Set(int driver)
{
    // check driver validity first
    Driver::check_driver(driver);
    Driver::driver = driver;
}

/**
 * @brief get the current driver
 * @return current driver as int
 **/
int Get()
{
    return Driver::driver;
}
} // namespace Driver

namespace Wheel
{
double pos = 1;

/**
 * @brief set the wheel position
 * @param pos: wheel position ranging from [-1,1]
 **/
void Set(double pos)
{
    Wheel::pos = pos;
}

/**
 * @brief get the wheel position
 * @return wheel position
 **/
double Get()
{
    return Wheel::pos;
}
} // namespace Wheel

/** @brief the main function */
int main(int argc, char **argv)
{
    // parse CLI
    CLI::App app{"Wizard Server"};
    // carla may be using 2000-2002
    uint16_t port = 2003;
    app.add_option("-p,--port", port, "port of the server");
    CLI11_PARSE(app, argc, argv);

    // creating server
    rpc::server server(port);
    server.suppress_exceptions(true);
    // driver setting
    server.bind("get_driver", Driver::Get);
    server.bind("set_driver", Driver::Set);
    // wheel synchronization
    server.bind("get_wheel", Wheel::Get);
    server.bind("set_wheel", Wheel::Set);

    // run
    std::cout << "Server starts listening on port " << port << "..."
              << std::endl;
    server.run();

    return 0;
}
