# Uncle Ben SkyJump

A simple variation of an old-school platformer developed in **C++** using the **SGG (Simple Game Graphics) Library**. It is a single-player game, where the player must climb platforms, avoid enemies, and reach the goal to win.



## Description
- The project is a 2-level vertical platformer.
- **Level 1:** Climb platforms and reach the spaceship.
- **Level 2:** Dodge UFOs and hazards, then reach the Moon to win.
- Background music and debug options are included.


## Rules
- Press **SPACE** to start the game.
- Move left and right with **A** and **D** keys.
- Jump with **W** (only when grounded).
- You must dodge the moving enemies (Badbirds in Level 1, UFOs in Level 2).
- If you collide with enemies, you lose the game.
- The goal is to successfully reach the spaceship (Level 1) and then the Moon (Level 2) to win.
- Music control: **M** to mute, **P** to resume.
- Press **Q** to exit after Win/Lose.
- Press **0** to toggle debug overlay.


## Install Dependencies
Ensure you have the **SGG (Simple Game Graphics) Library** installed on your system.  
Follow the instructions on the SGG library website for installation.


## How to Run

To run this Uncle Ben SkyJump project, follow these steps:

### Clone the Repository
```bash
git clone https://github.com/yourusername/UncleBenSkyJump.git
cd Unclebenskyjump
```

### Build the Project
Use a C++ compiler that supports the SGG library. For example, with **g++** you can run:

```bash
g++ -std=c++17 -o Unclebenskyjump main.cpp -lsgg
```
### Run the Game: Execute the compiled binary:

```bash
./Unclebenskyjump
```

