# LabaITProject

A series of small C++ and Blueprint-oriented tasks made in Unreal Engine 5 using the First Person Template with a Shooter Variant.

---

## Blueprint Features
*   **Camera:** Zoom in/out functionality.
*   **Targets:** Hit-counting target system.
*   **Movable Platforms:** Player-input driven platforms (up/down or sideways).
*   **Explosives:** Exploding barrels and throwable bombs.
*   **Interactive Doors:** Modular interaction using interfaces (e.g., some doors can be opened only by the player, others only via a button).
*   **Buttons:** Interface-driven buttons to interact with objects like doors.
*   **Portals:** Teleports the player to the next level with a confirmation widget. *[WIP: Restricting collision to the player and teleporting to a specific location rather than the level start position]*
*   **UI (Main Menu, Pause Menu & Options):** Features a difficulty scaler (affects damage and target requirements for level progression), window mode settings (Fullscreen, Windowed), and resolution settings (1920x1080, 1280x720). Also includes a level selector for unlocked levels.
*   **Save/Load System:** Slot-based system with deletion capabilities. Saves the player's position, current level, window mode, resolution, and difficulty.

## C++ Features
*   **Object Interaction:** Picking up and dropping objects.
*   **Detector:** Features a 180° range of sight, rotating towards the player if the line of sight is clear. *[WIP: Implement DistanceSquared]*
*   **Proximity Doors:** Sliding doors that automatically open and close based on player proximity using colliders.
*   **NPC Patrolling:** Behavior Trees and C++ Tasks for patrolling. Includes random point selection from a radius and PatrolPoints placed on the level ("Cyclic" and "Back-and-Forth" types).
*   **Patrol Point Data:** Uses arrays of structures containing Position and WaitTime, allowing each point to have a specific wait duration for the NPC.

---

## Topics Learned
*   Math for games
*   Interfaces with C++ and Blueprints
*   Enhanced Input System
*   Rendering, Visibility Checking, Anti-aliasing, and Ray Tracing
*   UE5 Gameplay Frameworks (Creating Game Instances)
*   Pathfinding (Navigation Mesh, Dijkstra, A*, Heuristics)
*   State Machines, Behavior Trees, and State Trees

---

## Game Jam
As a part of the course conclusion we also make another project for a 1-month-long game jam.

**Random Generatored Words:** "mrówki, szczoteczka do zębów, bok, narkotyk, kciuk" (ants, toothbrush, side, drug, thumb). We needed to pick 3 out of the 5 words to build a game around.

> **Topics Picked:** 1. bok (side), 2. kciuk (thumb), 3. szczoteczka do zębów (toothbrush)

**Check out the our project:**
[Cauldron of Complaints Repository](https://github.com/vvbocko/CauldronOfComplaints)
