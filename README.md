Minimal **howto** create an application for the ESP8266/ESP12E,ESP12F boards on Mac or Linux using PlatformIO and the Arduino kernel for ESP8266.

## Preparation
### MacOS only: USB-serial driver
MacOS needs a kernel-driver for the USB-serial functionality. For ESP12e/f modules, the chipset is CH341.

The github project [ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver) by Adrian Mihalko provides a MacOS driver for this chipset.

Installation via [homebrew](https://brew.sh):
```bash
brew tap mengbo/ch340g-ch34g-ch34x-mac-os-x-driver https://github.com/mengbo/ch340g-ch34g-ch34x-mac-os-x-driver
brew cask install wch-ch34x-usb-serial-driver
```
Upon successful installation, you should see a new device similar to `/dev/cu.wchusbserial1460`.

**Note:** Beginning with MacOS High Sierra 10.13, you need to reboot the Mac after installing the kernel driver. On first driver load, MacOS will block the driver. In `System Settings / Security & Privacy`, the driver can be enabled for loading.

**Note:** Linux already contains the required driver in the standard kernel. Simply plug in the ESP board.

### Installation of platformio
```bash
pip install platformio
```
[Platformio](http://platformio.org) supplies command line functionality to compile and flash the ESP12/ESP8266 chips (and many other platforms and chips).

#### IDE support
PlatformIO also integrates with Atom or VSCode: http://platformio.org/platformio-ide

* To init a new platformio project, simply define a platformio.ini file containing the platform=, framework=, and board= definitions.

For ESP chips with [Arduino kernel](https://github.com/esp8266/Arduino/), we use:
#### plaformio.ini:
```
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino
```
With
```
platformio init
```
A project structure is created. 

**Note:** the project structure is already created for this sample project, so no `init` is needed, if the project is cloned.

### Building the *blink* projeject
To compile, use:
```
platformio run
```
or:
```
pio run
```
On first use, this automatically installs the entire required tool-chain.

To compile & flash the ESP chip, use:
```
pio run -t upload
```
If upload fails, the most common cause is a failed detection of the USB-serial port in use. This again is mostly caused by a failed driver installation. Verify that you can actually see a new serial port when plugging in the ESP port via USB.

#### Successful build & upload
This should result in the onboard led of the ESP board blinking.

# References
* MacOS USB-serial driver, [ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver)
* [PlatformIO](http://platformio.org)
* [Arduino ESP kernel](https://github.com/esp8266/Arduino)
* [Arduino ESP documentation](http://esp8266.github.io/Arduino/versions/2.3.0/)
