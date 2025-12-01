# NebulaCore Roadmap: Survival Edition

Based on the goal of a **3D stranded fishing/survival/building game**, here is the minimal set of engine components required, stripping away general-purpose bloat.

## 1. Core Foundation (The "Must Haves")
- [ ] **Windowing & Input**: Open a window, capture mouse/keyboard (GLFW/SDL).
- [ ] **Time & Loop**: Fixed timestep loop for physics, variable for rendering.
- [ ] **Event System**: Dispatch events like `OnPlayerJump`, `OnItemPickup`.

## 2. Rendering (Visuals)
- [ ] **Render Context**: OpenGL or Vulkan setup.
- [ ] **Mesh & Shader System**: Load and draw 3D models.
- [ ] **Water Rendering**: **CRITICAL** for a fishing game. Needs reflection/refraction/waves.
- [ ] **Terrain System**: Heightmap or mesh-based terrain for the island.
- [ ] **Lighting**: Day/Night cycle (sun/moon movement), dynamic shadows.
- [ ] **Particle System**: Water splashes, fire, smoke.

## 3. Physics & Interaction (Gameplay)
- [ ] **Collision Detection**: Raycasting (for fishing line, building placement).
- [ ] **Character Controller**: Walking, jumping, swimming physics.
- [ ] **Rigid Bodies**: Simple physics for dropped items.

## 4. Scene & Assets (Data)
- [ ] **Asset Manager**: Load textures, models (.obj/.gltf -> .nebula), sounds.
- [ ] **Scene Graph / ECS**: Manage entities (Player, Trees, Fish).
- [ ] **Serialization**: Save/Load game state (inventory, built structures).

## 5. Game Specifics (The "Fun" Stuff)
- [ ] **Animation**: Skinned mesh animation for the player (casting, reeling).
- [ ] **Audio Engine**: 3D spatial sound (waves, wind, footsteps).
- [ ] **UI System**:
    - **Editor**: ImGui for tweaking values live.
    - **Game HUD**: Inventory, health bars, crosshair.

## 6. Blender Pipeline
- [ ] **Exporter**: Export terrain chunks, props, and player animations directly to engine format.
- [ ] **Hot-Reload**: Update assets in-game when saved in Blender.

## Recommended Order of Execution
1. **Window & Input** (So we can see something)
2. **Basic Rendering** (Draw a cube)
3. **Asset Import** (Get a Blender mesh on screen)
4. **Camera & Movement** (Fly around)
5. **Water & Terrain** (Set the scene)
