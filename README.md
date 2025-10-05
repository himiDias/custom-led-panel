# himiDias/custom-led-panel

Custom-led-panel - A **C++** application that can be used to control and customise a personal desk top LED Panel.

The project started as a fun experiment to explore handling and controlling external hardware whilst giving me hands-on experience with skills are tools.

## Brief

The application was coded in C++ using the [rpi-rgb-led-matrix](https://github.com/hzeller/rpi-rgb-led-matrix) library for configuring and controlling LED Panel on Raspberry Pi. Read further on the original repository for information on compatible Raspberry Pis, Panels and HATs.

This application was implemented and tested on a **64x64** Panel attached to a **Raspberry Pi 4 Model B** using an **Adafruit RGB Matrix HAT**.

Project structure is split into two main components:

- `src/led` controls the logic and functionality of the LED Panel.

- `src/http_server` controls a websocket commuincation using **Crow** with a **REACT** Web server hosted on LAN.

## Features

<img src = "/assets/panel_main.jpg" alt = "Main screen on panel" height ="300" width = "200">
 The start screen displayed on the LED when executing the program.

- Shows a status message, default to "Set Status Message" at the top of panel
- 4 Icons navigated to using the controller.
- Cog : Settings
- Paint Brush : Paint
- Controller Icon : Games (Not yet implemented)
- Star : Saved Screen Savers/Created Displays (Not yet implemented)

<img src = "/assets/site_main.jpg" alt = "Main screen on site" height ="400" width = "500">
The digital controller accessible via LAN (Mobile Landscape View)
<img src = "/assets/site_settings.jpg" alt = "Settings screen on site" height ="400" width = "500">
The Settings Screen accessible by selecting Cog Icon from LED (Mobile Landscape View)

- Allows users to set a custom status message
- Decide whether to show Today's Date, Current Time or neither.

<img src = "/assets/site_draw.jpg" alt = "Paint screen on site" height ="400" width = "500">
The Paint Screen accessible by selecting Paintbrush Icon from LED (Desktop View)

- Allows users to select any colour within the RGB colour spectrum
- Click and Drag on the 64x64 grid to set LED's on and update in real-time.
- Erase pixels

## Set up

- run `make`
- run `sudo ./bin/run_panel`

### REACT

- cd into `src/http_server/frontend`
- Change and Test
- run with `npm run dev -- --host`
- build with `npm run build`
