# LUCI Messages

This is a custom ros2 message package for LUCI SDK. 

## How to build this repo:

### Docker
- Follow the documentation on the SDK repository on [github](https://github.com/lucimobility/luci-ros2-sdk/tree/main/development) for manual setup in docker. 

### Native setup
- Follow the steps on the [luci-sdk](https://lucimobility.github.io/luci-sdk-docs/next/ROS2%20SDK/How-To/Installation/dependencies) repository main readme to install all the dependencies.
- You have two ways to install the SDK, one by using the provided debians and other by just cloning and buiding the repositories. These methods are explained in detail in the [installation](https://lucimobility.github.io/luci-sdk-docs/ROS2%20SDK/How-To/Installation/luci-ros2-sdk-install) steps.

### File struture to follow
```bash
ros_ws
└──luci-ros2
    └── src (Use colcon build at this level)
        ├── luci-ros2-grpc
        └── luci-ros2-msgs
```

Note: There is a potential that when running packages that import this library you will get an error about missing `luci_messages_runtime.so` or similar. If you are doing a `colcon build` this shouldn't occur but if you are building directly with CMake then this is due to the .so files being installed to `/usr/local/share` which is not apart of the LD_LIBRARY path. You can either edit that env variable when running any package that imports this one or you can set the RPATH in that packages CMake. 
See luci-grpc-interface for more instructions on this.

## Building with CMake (If needed)
1. cd into the root directory (one with package.xml)
2. run `mkdir build`
3. cd into build folder
4. run `cmake ..`
5. run `make -j4`
6. run `sudo make install`

<b>Note:</b> While I made a lot of effort to ensure the CMake build process works when using this library it added more hassle then it was worth with the above mentioned runtime library. 

There is also an automatic build script called `build-package.sh` that can be ran to build the installable `.deb` file. This is what the github actions call. You can use it if you want to just put the deb in the ros directory to run when ros is sourced. Better way is to just download the debian using apt.

## Releasing new version ##
When a new version of this package is ready to be released there are a couple steps to follow. It is important to note that most of the process is automated for convenience and the process should be just a couple of button clicks. 

### Steps ### 
1. Update release version
    - This should be its own separate PR and should only update the package.xml `<version> </version>` tag. 
    - LUCI follows [semver](https://semver.org/) style versioning so MAJOR.MINOR.PATCH versions are expected.
    - It is okay to not put out versions until multiple changes have happened to the code. 
2. Once the version increment is merged you simply need to create an official release in github. Make sure you make the release version the same as what is now in `package.xml`. We have chosen to keep github release and package version in sync.
    - This should trigger an action to auto run called `Create and Sign Package` which you can monitor in the github actions panel. This should grab the released code, build it, make an installable .deb file, gdb sign it and push it to jrog artifactory.  

If everything went smoothly congratulations the new package will be released and publicly distributable.


<b>NOTE: Once a PR is merged into the `main` branch the docs site in the `next` version will update with it that evening.</b>


[Implementation](docs/msgs_package.md)