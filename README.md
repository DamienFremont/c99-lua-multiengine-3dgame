# 3D Game Starter - Multi Engine (Unreal, Unity, Godot, Defold, Raylib, The Forge)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Twitter Follow](https://img.shields.io/twitter/follow/Damien_Fremont?style=social)](https://twitter.com/Damien_Fremont)
[!["Buy Me A Coffee"](./docs/buymeacoffee-20.png)](https://www.buymeacoffee.com/damienfremont)

:warning: **WORK IN PROGRESS !!!**

2025's exercise in game engine and logic modules.

Spoiler: Don't do it !!! Unless you intend to build your own custom engine in the futur, or be able to maintain your code in 20+ years.

Pros & Cons:
- less dependency to engine
- 

## Content

  - [Dependencies](#dependencies)
  - [Screenshots](#screenshots)
  - [Features](#features)
  - [Install](#install)
  - [Usage](#usage)
  - [Assets](#assets)
  - [Resources](#resources)

---------------------------------------

## Dependencies

- C++ 2020 / C 2017

## Screenshots

![alt text](./docs/diagrams-1.png)

![alt text](./docs/diagrams-2.png)

## Features

- Engine
  - [ ] Unreal (5.4.3)
  - [ ] Unity (6.0.1)
  - [ ] Godot (4.3)
  - [ ] Defold (1.9.1)
  - [ ] Raylib (5.0)
  - [ ] TheForge (1.58)
- Features
  - [ ] 3D
    - [ ] Camera (Third Person)
    - [ ] Skybox (Cube)
    - [ ] Inputs (Gamepad)
    - [ ] Lighting (World and Character)
    - [ ] Material (Texture or Shaders)
  - [ ] Physics
    - [ ] Gravity
    - [ ] Colision
  - [ ] Audio
    - [ ] Sound effects
  - [ ] UI
    - [ ] Main Menu
    - [ ] Settings Menu
- Examples:
  - [ ] "Unreal" First Person (FPS)
  - [ ] "Unreal" Third Person (TPS)
  - [ ] "Matrix" Demo (OpenWorld)

Repository layout:
```
├── assets
├── docs
├── infra
├── lib
├── platform
│   ├── engine
│   └── game
├── standalone
│   ├── unreal_desktop_win64
│   ├── unity_desktop_win64
│   └── ...
└── tools
    └── blender
    └── ci
```

# Unreal 5

## Create project

1. start Unreal:
    1. create project "MyGameUnreal5"
    2. menu -> edit -> plugins -> add -> third party -> "MyGame"
2. close Unreal
3. start VisualStudio
4. start Unreal

## Usage

1. start Unreal:
    1. menu -> tools -> open visual studio
2. VisualStudio:
    1. code...
    2. hot-reload code(Ctrl+Alt+F11)
3. Unreal
    1. play (Alt+P)
    2. test...
    3. detach camera / debug scene (F8)
    4. press ESC


- Unreal:
  - [UE4 3rd party library plugin workaround (YouTube)](https://www.youtube.com/watch?v=LZr-IDTM294)
  - [Adding custom third-party library to plugin from scratch](https://unrealcommunity.wiki/adding-custom-third-party-library-to-plugin-from-scratch-867b28)
