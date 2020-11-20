# adaptivefw
A Dynamic Firewall  
//TODO: add screenshots

## 1. DPDK Setup 
In this section, a step-by-step guide for setting up a DPDK environment will be provided. This guide assumes that an Ubuntu 20.04 virtual machine has been set up using Oracle VirtualBox, however, other versions of linux may also be compatible.  
DPDK version used - 19.11.5
### Step 1 - Configuring the Virtual Machine
Before installing DPDK, some network settings for the virtual machine need to be adjusted.   
* In the VM settings, enable two additional network adapters and attach both as Bridged Adapters.  
* Then, from the terminal inside the VM, run the ifconfig command to get a list of all active network interfaces, note the name of the second and third interface, these are the additionally opened ones.  
* Run the following command to shut the additional interfaces down  
  ``` Terminal
        sudo ifconfig <interface_name> down
  ```
* Just to make sure, the ifconfig command can be run again, this time it should just show the main network interface  

### Step 2 - Downloading and installing DPDK
* The latest long term stable release (currently 19.11.5) can be found on the [DPDK website](https://core.dpdk.org/download/)
* Unzip the downloaded archive in the desired install directory using
  ``` Terminal
        tar xf <archive-name>.tar.xz
  ```
* Once extracted, navigate to the usertools folder withing the DPDK root folder, several helpful scripts that allow for an easier installation can be found here.
* Run the dpdk-setup script using root privileges
  ``` Terminal
        sudo ./dpdk-setup.sh
  ```
  This will present the user with multiple options devided into different sections.
* From the first section, select the option corresponding to the desired build environment, in this case, it should be x86_64-native-linux-gcc.
* Once the above step is done, the option to insert the IGB UIO module should be selected. Right after this, select the option to Bind Ethernet/Baseband/Crypto device to IGB UIO module, this will prompt the user to input the name of the interface(s) to bind. Do this twice and bind the two interfaces that were shit down in step 1.
* Finally, hugepages should be set up by selecting the option to Setup hugepage mappings for NUMA systems, the default number of hugepages (64) can be used.

### Step 3 - Setting up environment variables
The last step is to export two environment variables which will enable building and execution of DPDK based applications. From the terminal, execute the following commands:
``` Terminal
        export RTE_SDK=/home/<username>/<dpdk_root_folder>
        export RTE_TARGET=<dpdk_root_folder>/x86_64-native-linuxapp-gcc
```
Everything should now be set up and the provided application can be build using make and run with root privileges from within the build directory.
``` Terminal
      sudo ./l2fwd -- -p3
```