# Wizard-Server

Additional server for exchanging information between clients.

## Usage

Just run the program and the server will bind to the specific port (default `2003`).

```bash
./bin/wizard-server [-p port]
```



## Build

This is a one file small project and can be compiled using `cmake`

+ install `cmake`

```bash
# ubuntu
sudo apt install cmake
```

+ configure and compile

```bash
mkdir build; cd build
cmake ..
cd ..
cmake --build ./build
```

+ the executable lies in the `bin` folder

```bash
./bin/wizard-server
```



## APIs

+ get_driver: get the current driver
  + return int (0 for user and 1 for wizard)
+ set_driver
  + param: driver: id of the driver
+ update_wheel_pos: upload the wheel position
  + `param ` int`[0,65535] indicating wheel position
+ get_wheel_pos: get the wheel position
  + `return ` int` wheel position
+ [ ] set_vehicle_id
+ [ ] get_vehicle_id
