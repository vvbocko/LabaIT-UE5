# LabaITProject

Series of small C++/Blueprints oriented tasks made in Unreal Engine 5 using First Person Template with Shooter Variant.

Added mechanics:

## Blueprints
- Camera Zoom in/out
- Target that counts hits
- Player Input Movable platforms (up/down or sideways)
- Exploding Barrels and Throwable bombs
- Doors closing and opening on interaction using interfaces (modular: ex. some doors can be opened only by player, some only via button)
- also using interfaces - buttons can be pressed to interact with doors for example
- Portal teleporting player to the next Level with confirmation widget [tba: only player can collide, teleports to next teleport location instead of the lvl start position]
- UI: Main Menu, Pause Menu and Options:
   - Difficulty (Uses dificulty scaler: affects damage and the number of targets that need to be shooted in order to go to the next level)
   - Window Mode (Fullscreen, Windowed, etc.)
   - Resolution (1920x1080, 1280x720, etc.)
   - Main/Pause Menus have: select level (only the ones that are unlocked)
-  Save/Load Game System with Slots that can be deleted (Saves: Player position, Current Level, Window Mode, Resolution, Difficulty)

## C++
- Picking up and dropping objects
- Enemy with 180° range of sight, rotating towards player if nothing's in the way [tba: use DistanceSquared]
- Automatically opening and closing sliding door (player proximity - collider)
- NPC Patrolling with Behavior Trees and C++ Tasks (variants: Random point from radius, PatrolPoints placed on level - "Cyclic" & "Back and Forth" Type of patrolling)
- Set Patrol points are used as arrays of structures{Position, WaitTime} - every patrol point can have set wait time for NPC 
##

# Learned topics:
- Math for games
- Interfaces with C++/Blueprints
- Enhanced Input System
- Rendering, Checking visibility, Antialiasing, Ray Tracing
- UE5 Gameplay Frameworks (Creating Game Instances)
- PathFinding (Navigation Mesh, Dijkstra, A*, Heuristics)
- State Machines, Behaviour Trees, State Trees


# Game Jam
The project ends with an around 1-month-long game jam

Theme (random words generator): "mrówki, szczoteczka do zębów, bok, narkotyk, kciuk" (ants, toothbrush, side, drug, thumb)
We need to pick 3 out of 5 words and make a game around those.

> Topics picked: 1.bok, 2.kciuk, 3.szczoteczka do zębów
> << [Link to repo of our project "Cauldron of Complaints" \](https://github.com/vvbocko/CauldronOfComplaints)>>
