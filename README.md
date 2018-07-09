# Network-everything
## Beacon project included <br/>

Main link >>> https://github.com/michaelshiloh/NetworkEverything

# Beacon: <br/>

## Project Description <br/>
"Do you feel constantly tired in your day to day life? Sense everything falling apart and control slipping away? Constantly questioning existence, universe, life and everything, and you feel that the answer is not just mere 42? Prepare yourself to experience the magical power of relaxation beacon. Our network of connected devices will detect your stress from overworking and will send you on a journey of tranquility. The scanner is connected to a server which in turn is connected to a "beacon"- resonance tube with mounted speakers which will play relaxing music suitable for destressing. Sublime Relaxation Beacon - the beacon that cares about you." <br/>

Through this projected, we attempted to activate the atriums, by turning it as a relaxation hub with brainwave music for tired and stressed students. The sender pi would be running at the stress-induced sites such as the library and scanning the MAC address of the students at the location. Those MAC Addresses would be sent to the database, and when the receiver pi at the atrium scans a MAC Address from the database, the receiver.py would remove the existing MAC address and welcome the stressed person with a "bong". <br/>

![2018-05-13 208-13 p m -1](https://user-images.githubusercontent.com/35731539/39969276-61bc4a1c-56ea-11e8-8fd3-d4b4fae91bc4.png)


## Process <br/>
Using all the components below, we came up with code sender.py (at the site) and receiver.py (at the atrium).

### Networking piece:

1. Scanning the Wifi <br/>
* Install required package on raspberry pi: ```pip install python3-nmap ``` or ```sudo apt-get install nmap``` <br/>
* Read through <a href="https://bitbucket.org/xael/python-nmap/src"> nmap </a> to learn more about network scanning.

2. Using a database (Firebase): <br/>
Networked two raspberry pis at different location using the database function on <a href="https://firebase.google.com/"> Firebase </a> . As raspberry pi works on python, used <a href="https://github.com/thisbejim/Pyrebase"> pyrebase </a>, a simple python wrapper for the Firebase API.<br/> 
* Install required package on raspberry pi: ```sudo pip install pyrebase```
* Make an account on Firebase, using Google.
* Create a project and go to Project settings to collect: Project ID, Web API Key and the link 

#### In case of using an enterprise network (Adapted from <a href="https://frillip.com/using-your-raspberry-pi-3-as-a-wifi-access-point-with-hostapd/"> USING YOUR NEW RASPBERRY PI 3 AS A WIFI ACCESS POINT WITH HOSTAPD </a>) by Matt Karau:
Install the required packages:
```sudo apt-get install dnsmasq hostapd``` <br/>
* hostapd - This is the package that allows you to use the built in WiFi as an access point
* dnsmasq - This is a combined DHCP and DNS server that's very easy to configure <br/>

Configure interfaces: <br/>
* Configure your wlan1 interface with a static IP. If you're connected to the Pi via WiFi, connect via ethernet/serial/keyboard first. 
* In newer Raspian versions, interface configuration is handled by dhcpcd by default. We need to tell it to ignore wlan1, as we will be configuring it with a static IP address elsewhere.
* Open up the dhcpcd configuration file with ```sudo nano /etc/dhcpcd.conf``` 
* Add the following line to the bottom of the file:``` denyinterfaces wlan1 ```  <br/>
Note: This must be ABOVE any interface lines you may have added! <br/>
