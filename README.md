# Necrodoggiecon

# How the project works
The engine holds all the intrinsic components and the other outer projects can create classes that inherit these components and then the class can be used to create the game ontop of the engine.

# Specific Areas I Worked on:
#### Collision Detection <br>
#### Weapons - See [Weapons](Doxygen/Markdown/Weapons.md) <br>

# Instructions

## How to compile the Engine
Open the CerberusEngine project in Visual Studio.
Right click on the project and click build.
Do not debug the engine, just build it. 

## How to compile the Game
Firstly, compile the engine.
Open the Necrodoggicon project in Visual Studio.
Right click on the project and set as startup project.
Set to release mode and press F5 to run the game.

## How to access documentation
The technical documentation is automatically generated using Doxygen. To view the generated documentation for this project see the generated PDF [HERE](https://github.com/lukewhitingdev/Necrodoggiecon/blob/802443daefeac5c17fe42729b03e21891f46ef48/Technical%20Documentation%20PDF.pdf).
<br>
### To generate / contribute documentation.
Firstly, to add auto-styled doxygen comments, use of the Visual Studio Extension [Doxygen Comments](https://marketplace.visualstudio.com/items?itemName=FinnGegenmantel.doxygenComments)<br>
To generate the documentation, a doxygen binary is required. This is the responsibility of the developer sadly as including Doxygen source in this project would increase the project size dramatically.

## How to play the Game
### Controls:
-   WASD - Movement
-   Left click - Fire weapon
-   F - Interact

## Naming Convention

### Variables:
varNameHere.

### Functions:
FunctionNameHere.

### Enums, Defines:
ANGRYENUMS

## Links to the aspects of the Engine/Game

-   [AI](Doxygen/Markdown/AI.md)
-   [AssetManagement](Doxygen/Markdown/AssetManagement.md)
-   [Audio](Doxygen/Markdown/Audio.md)
-   [Editor](Doxygen/Markdown/Editor.md)
-   [UI](Doxygen/Markdown/UI.md)
-   [Utility](Doxygen/Markdown/Utility.md)
-   [Weapons](Doxygen/Markdown/Weapons.md)
-   [World](Doxygen/Markdown/World.md)


