# luci_messages

## summary:

This is a custom message package for message types that are LUCI specific.

| Package | Message |
|---------|---------|
| luci_messages | LuciJoystick <br/><br/> `int32 forward_back` <br/> `int32 left_right` |
|  | LuciScaling <br/><br/> `float front_fb` <br/> `float front_rl` <br/> `float front_right_fb` <br/> `float front_right_rl` <br/> `float front_left_fb` <br/> `float front_left_rl` <br/> `float right_fb` <br/> `float right_rl` <br/> `float left_fb` <br/> `float left_rl` <br/> `float back_right_fb` <br/> `float back_right_rl` <br/> `float back_left_fb` <br/> `float back_left_rl` <br/> `float back_fb` <br/> `float back_rl` <br/> `uint32 max_js_scale_increase` <br/> `uint32 max_js_scale_decrease` <br/> `bool luci_active` |
|  | LuciDriveMode <br/><br/> `enum` <br></br> `USER=1 ENGAGED=2 AUTO=3` |


The LUCI scaling zones message is based on the on the chair scaling LUCI uses. Scaling is broken up into 8 zones seen below. In each zone there also exists a scaling for forward/back and left/right. LUCI determines which zone the joystick is currently in based on the angle of the joystick per the image below. This indicates the percent scaling that would be applied to a joysticks (forward back, left right) values if placed in one of the 8 zones.

For example if the joystick was at an angle of 5 degrees from center (placing it in the front zone) and LUCI had a front_fb scaling value of 0.5 and a front_rl scaling value of 1.0 then LUCI would scale the joystick in the Y axis by 50% and would let 100% scaling in the x axis (relative to chair coordinates)

![luci scaling image](zone-ring.png)
![luci zone image](zones.png)
