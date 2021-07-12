# Victoria

![Victoria](/Resources/Branding/Victoria-500.png?raw=true "Victoria")

Victoria is primarily an early-stage interactive application and rendering engine for Windows.

## Current Status

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/org-Stupefy/Victoria)

![build](https://github.com/org-Stupefy/Victoria/workflows/Win-build/badge.svg)

## Getting Started

Visual Studio 2017 or 2019 is recommended, Victoria is officially untested on other development environments.

Start by cloning the repository with `git clone --recursive https://github.com/org-Stupefy/Victoria.git`

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

## Building

Victoria uses premake5 for generating solutions. Run the [Win-GenProjects.bat](scripts/Win-GenProjects.bat) from scripts folder and it will generate vs19 solution file.

<!-- You can view the project status here [Status](/Resources/Branding/results.md) -->

## Projects using Victoria

Below is the list of projects that are developed using Victoria Engine

- [BoostRocket](https://github.com/org-Stupefy/BoostRocket)
  - Boost Rocket is a simple 2D game that was developed to test Victoria during development.
