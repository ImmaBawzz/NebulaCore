# NebulaCore Architecture

NebulaCore is designed as a modular game engine where every system is a module.

## Core Concepts

### EngineConfig
Handles startup options, modules to load, and paths.

### IModule
Abstract interface for any engine module (rendering, physics, audio, scripting).
Lifecycle methods:
- `OnRegister()`: Called when engine loads module.
- `OnUpdate(float dt)`: Called every frame.
- `OnShutdown()`: Called when engine shuts down.

### Application
Bootstraps everything, runs the main loop, and dispatches events.

### PluginManager
Loads external plugins.

## Directory Structure
- `engine/core`: Core systems (Application, Module interface, Logging)
- `engine/rendering`: Rendering system
- `engine/scene`: Scene graph and ECS
- `engine/scripting`: Scripting support
- `engine/plugins`: Plugin system and default plugins
