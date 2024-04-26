### Instructions

## IDE
You can use whatever you want, I'd recommend downloading the Arduino IDE as it has some good examples with it,
but for actual dev work I find VSCode with PlatformIO add-on better to work with.

- [Official Arduino IDE](https://www.arduino.cc/en/software)
- [Visual Studio Code](https://code.visualstudio.com/)
  - Then search for [PlatformIO](https://platformio.org/) in extensions.

## Simulation
We can simulate the lighting setup using [wokwi.com](https://www.wokwi.com). It's free to start an account and you can create multiple projects.
Chrome is recommended over other browsers as apparently it yields the best performance. It is quite resource-heavy so I'd recommend closing any applications and tabs that are not being used to free up memory and processing power for the simulator.

## Getting Started
You don't need a Github but I would recommend it, it's free and it lets you subscribe to changes in the project so you'll get an email whenever there's a change, but if you don't want to start one or use your own, then that's totally fine.

If using Github, clone the project and work away, create branches and pull requests if you want, or just commit directly, we can fix any issues with reverts if needed.

To subscribe to changes, click on the `Watch` button with the eye symbol, and select `All Activity`.  You'll get email notifications when new changes have been made.

If not using Github account, you can download a zip of the codebase and open it in VSCode, and make your changes. When external changes come in, you'll either need to download a new zip, or just manually copy paste from Github in the browser.

If you don't want to bother with any of this, you can directly copy paste code from the Github directly into Wokwi in the browser and make your changes there, then send on the code however you want, e.g. link to you Wokwi project, zip and add to whatsapp, or add a comment in Github and paste it there.

There are two files you need to run the project, currently they are `main_parallel.cpp`, which is the code of the project, and `diagram_parallel.cpp` which is the schema for the simulation (which won't be changed that often).

## Steps
1. Create a [new project in Wokwi](https://wokwi.com/projects/new) using Arduino Mega.
2. Copy all the code from [src/main_parallel.cpp](https://github.com/ConorGarry/ArduinoPlayground/blob/main/src/main_parallel.cpp) and paste it into `sketch.ino` (ino is arduino bespoke format, but it's C++ under the hood).
3. Copy all the code from [diagram_parallel.json](https://github.com/ConorGarry/ArduinoPlayground/blob/main/diagram_parallel.json) into the `diagram.json` tab in Wokwi.
4. Press the play icon in the simulator. You should see something like this:

![Kapture 2024-04-26 at 09 15 08](https://github.com/ConorGarry/ArduinoPlayground/assets/6222596/f462a347-72d3-42c8-bbd7-b6267ed3380b)

_Note: Due to the scale of the project, you'll need to zoom in and out a lot to see a close-up for the schema and to flick the switches._

At this point, you'll see it's running the default mode (0) which is the `rainbowChase()` function.

## Switches (be trippin')
There are 5 on/off state switches for selecing the 32 (5^2) different modes.
The simulator uses slide switches, which have simple persisted on/off states, on = 1, off = 0, the real-life model will use same principle.

<img width="330" alt="Screenshot 2024-04-26 at 17 59 34" src="https://github.com/ConorGarry/ArduinoPlayground/assets/6222596/6ab3674e-ffe4-40d1-9913-c9ce0abdef77">  

_5 Switches in sequence, representing 5 binary digits._


<img width="79" alt="Screenshot 2024-04-26 at 17 59 40" src="https://github.com/ConorGarry/ArduinoPlayground/assets/6222596/9655d0b6-bd6e-4abe-8392-2d4061ac535c">  

_Switch in *off* position, or `0` value_


<img width="69" alt="Screenshot 2024-04-26 at 17 59 49" src="https://github.com/ConorGarry/ArduinoPlayground/assets/6222596/4c7a6031-4fad-43d2-b564-185ec64131cd">  

_Switch in *on* position, or `1` value_


Using this pattern, we can use the switches to represent a 5 digit binary number. So to select between the first four (because at time of writing this there are four patterns), the switches would be set accordingly:

|Binary Value| Mode |
|-|-|
|`00000`|`0`|
|`00001`|`1`|
|`00010`|`2`|
|`00011`|`3`|
|`00100`|`4`|

- The switches are only toggleable when the simulator is running, they won't change when it is paused.
- If the simulator has been stopped, the state will be persisted, i.e. next time you press play, it will resume with the most recent pattern you had selected.
- The switches are quite small, so you'll be zooming in and out a lot, get used to whatever shortcut you use for that, be it keyboard or touchpad.


## TODO:
- Adding new functions.
- Resources.

