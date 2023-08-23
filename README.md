# LUCI Messages 

## How to build this repo:
1. Run the development docker image hosted in the luci-sdk repo (or on jfrog)
2. Follow the steps in the docker image to clone this repo into the image
3. Go to the root directory of this repo (the directory with package.xml)
4. Run `colcon build`
5. To use the luci messages in other packages such as luci-grpc-interface source the install dir
` source install/setup.bash`

Note: There is a potential that when running packages that import this library you will get an error about missing `luci_messages_runtime.so` or similar. If you are doing a `colcon build` this shouldn't occur but if you are building directly with CMake then this is due to the .so files being installed to `/usr/local/share` which is not apart of the LD_LIBRARY path. You can either edit that env variable when running any package that imports this one or you can set the RPATH in that packages CMake. 
See luci-grpc-interface for more instructions on this.

## Building with CMake 
1. cd into the root directory (one with package.xml)
2. run `mkdir build`
3. cd into build folder
4. run `cmake ..`
5. run `make -j4`
6. run `sudo make install`

<b>Note:</b> While I made a lot of effort to ensure the CMake build process works when using this library it added more hassle then it was worth with the above mentioned runtime library. 

I did play with making a second "Interface" library that links against the generated msg files and could be easily included as a wrapper in other projects. The thought was this would be an easier import as it was just regular CMake and should be able to better locate the runtime .so files without the need for all the LD_LIBRARY path edits mentioned above. This had some success but I believe needs to be made as a static library instead of the default .so. This is worth looking into more but as `colcon build` and sourcing works for our pipeline for now it was put on hold.

There is also an automatic build script called `build-package.sh` that can be ran to build both the ROS package and an installable `.deb` file. This is what the github actions call.

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