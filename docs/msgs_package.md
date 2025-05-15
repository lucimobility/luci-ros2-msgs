# luci_messages

## Summary:

This is a custom message package for message types that are LUCI specific.

| Luci Messages     | Message Details                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| ------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| LuciJoystick |  `int32 forward_back` <br/> `int32 left_right` <br/> `int32 joystick_zone` <br/> `int32 input source`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
|     LuciJoystickScaling          |  `int32 forward_back (scaled forward back limit)` <br/> `int32 left_right (scaled left right limit)` <br/> `int32 joystick_zone` <br/> `int32 input_source` <br/> `float32 forward_back_scaling` <br/> `float32 left_right_scaling`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
|     LuciZoneScaling          |   `float32 front_fb` <br/> `float32 front_rl` <br/> `float32 front_right_fb` <br/> `float32 front_right_rl` <br/> `float32 front_left_fb` <br/> `float32 front_left_rl` <br/> `float32 right_fb` <br/> `float32 right_rl` <br/> `float32 left_fb` <br/> `float32 left_rl` <br/> `float32 back_right_fb` <br/> `float32 back_right_rl` <br/> `float32 back_left_fb` <br/> `float32 back_left_rl` <br/> `float32 back_fb` <br/> `float32 back_rl`                                                                                                                                                                                                                                                                                  |
|       LuciImu        |  `std_msgs/Header header` <br/> `float32 quaternion_x` <br/> `float32 quaternion_y` <br/> `float32 quaternion_z` <br/> `float32 quaternion_w` <br/> `float32 acceleration_x` <br/> `float32 acceleration_y` <br/> `float32 acceleration_z` <br/> `float32 gyro_x` <br/> `float32 gyro_y` <br/> `float32 gyro_z` <br/> `float32 euler_x` <br/> `float32 euler_y` <br/> `float32 euler_z` <br/> `float32 accelerometer_x` <br/> `float32 accelerometer_y` <br/> `float32 accelerometer_z` <br/> `float32 magnetometer_x` <br/> `float32 magnetometer_y` <br/> `float32 magnetometer_z` <br/> `float32 gravity_x` <br/> `float32 gravity_y` <br/> `float32 gravity_z` <br/> `int32 cal_system` <br/> `int32 cal_gyroscope` <br/> `int32 cal_accelerometer` <br/> `int32 cal_magnetometer` <br/> `int32 source` <br/> `uint32 edge_timestamp` |
|         LuciEncoders      | `float32 left_angle` <br/> `float32 right_angle` <br/> `float32 fl_caster_degrees` <br/> `float32 bl_caster_degrees` <br/> `float32 fr_caster_degrees` <br/> `float32 br_caster_degrees` <br/> `uint32 edge_timestamp`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|      LuciCameraInfo         |  `float32[4] intrinsics (fx,fy,ppx,ppy)` <br/> `float32[3] translation (x,y,z meters camera->chair center)` <br/> `float32[3] rotation (x,y,z radians) camera -> chair center` <br/> `enum type RADIAN=0 DEGREE=1`<br/>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |

The LUCI scaling zones message is based on the on the chair scaling LUCI uses. Scaling is broken up into 8 zones seen below. In each zone there also exists a scaling for forward/back and left/right. LUCI determines which zone the joystick is currently in based on the angle of the joystick per the image below. This indicates the upper limit the joystick would be allowed to be (forward back, left right) if the joystick is placed in one of the 8 zones.

For example if the joystick was at an angle of 5 degrees from center (placing it in the front zone) and LUCI had a front_fb scaling value of 0.5 and a front_rl scaling value of 1.0 then LUCI would allow the max joystick in the Y axis to be +/- 50 (or 50% of full throw) and would let the max js in the x axis to be +/- 100 (or 100% of full throw) (relative to chair coordinates).

For the encoder data stream the `edge_timestamp` is expected to be a constant timer from the encoder or processing board's clock. Ideally this clock is produced from as close to the source of the readings as possible. For example with the encoder setup described here https://github.com/lucimobility/luci-sdk-encoders the edge_timestamp will be the milliseconds since the arduino control board booted up. This is using the [millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/) call in arduino. 

<b>Note:</b>

The LuciJoystickScaling message has the joystick values with the LUCI scaling applied as well as the scaling applied. These are the values most recently used to control the chair and have already been sent to the wheelchairs drive controller. Please note this message also contains the scaling zone that was used for these outputs.

Input source parameter is added to LuciJoystick and LuciJoystickScaling. This parameter denotes which input source has been set by the user. If this is used in any place to send commands to LUCI, make sure it is set to the same input as the desired/set state on LUCI or LUCI will disregard the command.

The input source are mapped as following:

| Integer | Input Source      |
| ------- | ----------------- |
|    0    |  RampAssist       |
|    1    |  AutonomousRemote |
|    2    |  WDI              |
|    3    |  ChairVirtual     |
|    4    |  ChairPhysical    |
|    5    |  SharedRemote     |

The joystick zones are mapped as following:

| Integer | Joystick Zone   |
| ------- | --------------- |
|    0    |  Front          |
|    1    |  FrontLeft      |
|    2    |  FrontRight     |
|    3    |  Left           |
|    4    |  Right          |
|    5    |  BackLeft       |
|    6    |  BackRight      |
|    7    |  Back           |
|    8    |  Origin         |

The LuciJoystick message also has the LUCI scaling zone that the input JS would fall in.

![luci scaling image](zone-ring.png)
![luci zone image](zones.png)
