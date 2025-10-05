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

## Set up

- run `make`
- run `sudo ./bin/run_panel`

### REACT

- cd into `src/http_server/frontend`
- Change and Test
- run with `npm run dev -- --host`
- build with `npm run build`
