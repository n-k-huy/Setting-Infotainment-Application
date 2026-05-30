# Setting Infotainment Application

## Introduction

This project is a C++ console application for managing vehicle infotainment settings.

The application allows users to input, update, and print different setting groups of a car, including display settings, sound settings, and general settings. It also loads language and time zone options from text files.

**Goal**: Practice C++ OOP concepts such as inheritance, polymorphism, abstraction, and dynamic memory management while building a simple automotive infotainment setting management system.

## Features

- Input car owner information such as name, ID, email, ODO, and service reminder distance
- Manage display settings:
  - Light level
  - Screen light level
  - Taplo light level
- Manage sound settings:
  - Media volume level
  - Call volume level
  - Navigation volume level
  - Notification volume level
- Manage general settings:
  - Language
  - Time zone
- Print display, sound, general, or all setting information
- Load language options from `Language.txt`
- Load time zone options from `TimeZone.txt`
- Load initial setting data from `Setting.txt`
- Use OOP to separate common car information and specific setting groups

## Technologies

- C++
- OOP
- File handling with `fstream`
- Smart pointer `std::shared_ptr`
---
## Architechture/Flow

```text
[Setting.txt]
     ↓
[main.cpp parses data]
     ↓
[Create Display / Sound / General objects]
     ↓
[Store objects in listFeature]
     ↓
[Menu system in Setting.cpp]
     ↓
[Input / Update / Print / Sort settings]
```

## Project Structure

```text
Setting-Infotainment-System-Application/
│
├── main.cpp                    # Application entry point
│
├── Car_infor.h/.cpp            # Stores common car/user information such as owner name, personal ID, email, ODO, and service reminder distance.
│
├── Display.h/.cpp              # Manages display settings such as light level, screen light, and taplo light
│
├── Sound.h/.cpp                # Manages sound settings such as media, call, navigation, and notification volume
│
├── General.h/.cpp              # Manages general settings such as language and time zone
│
├── Setting.h/.cpp              # Handles the main setting menu flow
│
├── listFeature.h/.cpp          # Template module for storing, displaying, searching, and sorting setting records
│
└── Common.h/.cpp               # Contains shared helper functions for reading language and time zone data
```

### Data Storage Format

The project loads initial setting records from `Setting.txt`.

Each line contains one full car infotainment setting record.

General format:

```text
Common: OwnerName/Email/ID/ODO/ServiceRemind Display: Light/ScreenLight/TaploLight Sound: Media/Call/Navigation/Notification General: Language/TimeZone
```

Example:

```text
Common: kim huy/nguyenhuy@gmail.com/12345678/4567/5000 Display: 1/2/3 Sound: 1/2/3/4 General: Vietnamese/(GMT+07:00) Bangkok, Hanoi, Jakarta
```

## What I learn?

1. Design a C++ console application using OOP.
2. Separate common vehicle information and specific infotainment setting modules.
3. Apply inheritance by creating `Display`, `Sound`, and `General` classes from the `Car_infor` base class.
4. Use polymorphism with `std::shared_ptr<Car_infor>` to manage different derived objects.

## Current Limitations

- New or updated data is mainly stored in memory during runtime and is not fully written back to `Setting.txt`.
- Input validation can be improved for ID, email, number ranges, and menu choices.
- Some menu handling logic is repeated between Display, Sound, and General settings.

## Author
- **Full Name**: Nguyen Kim Huy
- **Major**: Automotive Engineering Technology
- **Github**: ***https://github.com/n-k-huy***
