# SoftwareDevCA1 - Michael Heffernan

**Game Name:** Blob you're it!

Blobby is the fastest of all his slime friends and strives to survive in their annual tag festival, where the longest survivor is crowned Best Blob. Can you help blobby be the best blob in Blobberton.

**Controls**

Up: (W) or Up Arrow

Down: (S) or Down Arrow

Left: (A) or Left Arrow

Right: (D) or Right Arrow

SpeedBoost: SpaceBar

Pause: (P)

## Journal

### 11/11/23
Created copied an existing template for Raylib and used this to create my new repo.

### 01/12/23
Unfortunately I was not able to begin this until a few days before the deadline. I was researching and putting a general plan into practice, but due to work and life commitments, I did not begin on development until today.

### 03/12/23
With only a few hours left to have the assigment handed in, I am stopping development. There are many areas where I would like to improve on, especially if I want to add this to a portfolio, but it has an interesting base.

## Game Points

I decided to focus on a top down view and move across the map, which I felt was an interestin challenge. Instead of moving the character, I am moving the map around the character. This gave some interesting positioning challenges with enemies/pathing and needing to move the map in the opposite direction that the player wants to travel.

I created the map texture using a tileset and the tiled program. I then imported it along with some character textures.

I first drew the map and then implemented the controls on the main.css file. Once I had added enough details, I decided to break this out into a BaseClass and Child Class for the player character. I then created another Child Class for the enemy character.

I found it a little difficult to get my head around how movement should work in this topdown game, where Vector{0,0} is our initial point of contact and we draw everthing else as a reference from there. 

With regards to the Briefs Features, I have everything here included:
### Features

•	Opens a window 

•	Has Sprites/3D Models: Includes textures, shapes, shaders, 3D models 

•	Capable of user input: Game controller, mouse input, keyboard input, use of camera 

•	Sprites/3D Models capable of: Movement, animation, collisions 

•	Plays audio: Background audio or individual audio clips 

•	Includes text: Load different fonts 

•	Uses git/github source control

•	Use of header and source files

### Advanced Features
•	Enemy AI  - enemies follow the player

•	Different control schemes - keyboard different layouts

•	SpeedUp system when pressing spacebar - has a cooldown


All Basic and OOP Features have been included.

## References

### Used Assets
All of the used items were copyright free.

Tileset: https://stealthix.itch.io/rpg-nature-tileset 

Map Creator: https://thorbjorn.itch.io/tiled

Slime textures: https://admurin.itch.io/top-down-mobs-slime

Background Music:  https://tallbeard.itch.io/music-loop-bundle

SpeedBoost sound: https://pixabay.com/sound-effects/whoosh-6316/

Font 1: https://www.fontspace.com/blopy-font-f94047

Font 2: https://www.fontspace.com/ooky-font-f4176

### Unused assets

Slime Move: https://pixabay.com/sound-effects/jump-sound-ver-2-6093/

Loss Sound: https://pixabay.com/sound-effects/videogame-death-sound-43894/

Win Sound: https://pixabay.com/sound-effects/success-fanfare-trumpets-6185/

Countdown: https://pixabay.com/sound-effects/countdown-5-1-by-jenni-nexus-80911/

### Tutorials and guides looked at

Refrenced the college videos that we previously undertook and also further looked at:

It did seem like Raylib did not have as much detailed guides out there compared to unity or unreal.

Making games in raylib: https://www.gamedev.tv/p/cpp-fundamentals

Using timers in raylib: https://www.youtube.com/watch?v=vGlvTWUctTQ

General raylib use: https://github.com/raylib-extras/examples-cpp

Timer information: https://github.com/raysan5/raylib/wiki/Frequently-Asked-Questions#how-do-i-make-a-timer

Raylib Examples: https://www.raylib.com/examples.html