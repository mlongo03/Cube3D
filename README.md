# Cub3d

Cub3d is a project aimed at creating a 3D game using raycasting techniques reminiscent of early 3D video games like Wolfenstein. Developed in C and utilizing the graphic library named MiniLibX, Cub3d is a journey into the world of raycasting and video game rendering.

## Features

- **Raycasting Rendering**: Render the player's view in 3D based on a map that consists of walls, doors, and the player's position.
- **Collision Detection**: Implement collision detection with walls to ensure realistic movement within the game world.
- **Dynamic Minimap**: Display a dynamic minimap that follows the player's movements, providing a top-down view of the map.
- **Animated Doors**: Doors located at half-block positions on walls slide open when interacted with, featuring sprite animation.
- **Custom Textures**: Texture each side of the walls (North, South, East, West) with any desired image.
- **Player Movement**: Control player movement using the WASD buttons.
- **Door Interaction**: Open doors using the spacebar.
- **View Rotation**: Rotate the player's view using arrow buttons or mouse controls.

## Getting Started

To run the program, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the repository directory.
3. Run `make` in the terminal to compile the C files and create an executable named `Cub3d`.
4. Execute the program by running `./Cub3d <path to map configuration file>` in the terminal.

## Map Configuration File

The map configuration file initializes various aspects of the game environment:

- **Floor and Ceiling Colors**: Define colors for the floor and ceiling.
- **Wall Textures**: Specify images for each side of the walls (North, South, East, West).
- **Map Layout**: Create the map layout using digits, where:
  - "1" represents a wall.
  - "0" represents the floor.
  - The player position is represented by cardinal points letters to detect also its direction: "S", "N", "W", "E".
  - "2" represents a door position, with doors defined by two adjacent walls.

Example map configuration file:
```
F 220,100,0
C 70,70,70
NO ./textures/brick_wall_north.xpm
SO ./textures/brick_wall_south.xpm
EA ./textures/brick_wall_east.xpm
WE ./textures/brick_wall_west.xpm
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
```

## Controls

- **Movement**: Use the WASD keys to move around the map.
- **Door Interaction**: Press the spacebar to open doors.
- **View Rotation**:
  - Use the arrow buttons to rotate the view.
  - Alternatively, use mouse controls to rotate the view.

## Contributing

Contributions are welcome! Feel free to open issues or pull requests to suggest improvements, report bugs, or add new features.
