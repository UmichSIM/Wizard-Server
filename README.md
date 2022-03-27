# Wizard-Server

Additional server for exchanging information between clients.

## APIs

+ get_driver: get the current driver
  + return int (0 for user and 1 for wizard)
+ set_driver
  + param: driver: id of the driver
+ update_wheel_pos: upload the wheel position
  + `param: `int`[0,65535] indicating wheel position
+ get_wheel_pos: get the wheel position
  + `return: `int` wheel position
+ [ ] set_vehicle_id
+ [ ] get_vehicle_id
