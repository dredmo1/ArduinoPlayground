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

## TODO:
- Switches.
- Adding new functions.
- Resources.

