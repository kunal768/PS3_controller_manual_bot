# Configuring PS3_Controller to control a Robot 
Made with :heart: in [Team Technocrats Robotics](https://github.com/technocrats-robotics) for MR1 robot control ABU-National-Robocon19 <br>

## Hardware Used
<ul>
  <li>PS3/XBOX controller </li>
  <li>Raspberry Pi</li>
  <li>Arduino</li>
  <li>Obviously the Robot :sweat_smile:(Motors , Racks , Gripper etc.) </li>
</ul> <br>

## Pre-Requisite
```
Setting up a raspberry pi via a proper SSH connection 
```
``` 
Connect the controller USB to the raspberry pi 
```
![Conncection](https://github.com/kunal768/PS3_controller_manual_bot/blob/master/public/pi-pd.jpg)

## Setup 

Setup your raspberry pi <br><br>
Once the pi is connected , in the SSH terminal : 
```
cd path\to\cloned\folder\

pip install -r requirements.txt

export DISPLAY=:0

python main.py
```



## Glimpse Of Our Robo
<img src = "https://github.com/kunal768/PS3_controller_manual_bot/blob/master/public/WhatsApp%20Image%202019-05-01%20at%204.31.10%20PM.jpeg" > 
