# OaklandU-Octagon

### Summary
The Octagon Robot at Oakland University is a collaborative effort with the end goal of giving autonomous tours around campus.
As it stands it is capable of following a GPS path and will include computer vision capabilities in future iterations.
This repository serves as a place to maintain and source the code to run the robot. Documentation on individual components is held in 
the `docs` folder while the ROS code and packages reside in the `src` folder.

### Running the Robot Manually

When the robot is powered on, you will see on orange light blinking quickly on the RC receiver. 
To connect the RC controller, press and hold the trainer switch on the upper left hand side of the controller then switch it on.

<img src="https://github.com/racingrayson/OaklandU-Octagon/raw/main/docs/pictures/IMG_2296.jpeg" alt="IMG_2296" width="300"/>
Continue to hold the trainer switch until the light on the RC receiver is continuously on.

<img src="https://github.com/racingrayson/OaklandU-Octagon/raw/main/docs/pictures/IMG_2297.jpeg" alt="IMG_2297" width="300"/>
At that point the motor controller will take RC inputs and you can maneuver the robot with the right hand stick.

### Using the OU Laptop

The password used to sign in to the laptop and install new packages is: **voldemort1**

To get to the program workspace open the terminal and enter the following.

```cd ~/octagon```

From the workspace directory you can run the GPS path-following progam by entering:

```roslaunch run_prog main.launch```

This runs a launch file the collects and launches all of the necessary ROS nodes.

### Defining a GPS Path
The path is determined by a list of GPS coordinates which are definied in the .YAML files in `~/octagon/src/run_prog/config`

An example file is shown below.

<img src="https://github.com/racingrayson/OaklandU-Octagon/raw/main/docs/pictures/waypoints.png" alt="waypoints" width="600"/>
