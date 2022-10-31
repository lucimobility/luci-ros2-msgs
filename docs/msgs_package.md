# luci_messages

## summary:

This is a custom message package for message types that are LUCI specific.

| Package | Message |
|---------|---------|
| luci_messages | LuciJoystick <br/><br/> `int32 forward_back` <br/> `int32 left_right` |
|  | LuciScaling <br/><br/> `float front_fb` <br/> `float front_rl` <br/> `float front_right_fb` <br/> `float front_right_rl` <br/> `float front_left_fb` <br/> `float front_left_rl` <br/> `float right_fb` <br/> `float right_rl` <br/> `float left_fb` <br/> `float left_rl` <br/> `float back_right_fb` <br/> `float back_right_rl` <br/> `float back_left_fb` <br/> `float back_left_rl` <br/> `float back_fb` <br/> `float back_rl` <br/> `uint32 max_js_scale_increase` <br/> `uint32 max_js_scale_decrease` <br/> `bool luci_active` |
|  | LuciDriveMode <br/><br/> `enum drive_mode` |


The luci scaling zones message is based on grouping scaling into 8 zones each is split into a forward back and a left and right value. This indicates the percent scaling that would be applied to a joysticks (forward back, left right) values if placed in one of the 8 zones. See the image below for the configuration of the 8 zones.

![luci scaling image](luci-scaling.png)