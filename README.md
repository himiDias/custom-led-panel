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

<div style="display:flex; gap:10px">
<figure>
<img src="/assets/panel_main.jpg" alt = "LED Panel - Main Screen" width = "300" height = "400">
<figcaption>Main Screen of Panel</figcaption>
</figure>

<figure>
<img src="/assets/site_main.jpg" alt = "Site - Main Screen" width = "300" height = "400">
<figcaption>Main Screen of Controller on Mobile</figcaption>
</figure>

<figure>
<img src="/assets/site_settings.jpg" alt = "Site - Settings Screen" width = "300" height = "400">
<figcaption>Settings Screen of Controller on Mobile</figcaption>
</figure>

<figure>
<img src="/assets/site_draw.jpg" alt = "Site - Draw Screen" width = "300" height = "400">
<figcaption>Drawing Screen of Controller on Desktop</figcaption>
</figure>

</div>

## Set up

- run `make`
- run `sudo ./bin/run_panel`

### REACT

- cd into `src/http_server/frontend`
- Change and Test
- run with `npm run dev -- --host`
- build with `npm run build`
