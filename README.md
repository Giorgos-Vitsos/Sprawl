# Sprawl

Sprawl is a 3D graphics engine and procedural generation project built from scratch in C++ and OpenGL.
I'm building everything from the ground up — the renderer, scene system, asset pipeline, editor, particle simulation, and eventually a procedural city generator.
The goal is to understand how these systems work by actually building them, rather than relying on an existing engine.

## Roadmap

### Phase 1 — Renderer
Building the OpenGL core structure.
*   **Window System:** GLFW integration.
*   **Shader System:** Load/compile/link `.vert` and `.frag` files.
*   **Vertex Buffers:** VBO, VAO, EBO/IBO management.
*   **Mesh:** Abstractions for cube, sphere, plane.
*   **Camera:** Position, Rotation, FOV, Near/Far planes, Perspective projection.
*   **Transform:** Position, rotation, and scale data structure.

### Phase 2 — Engine
Moving from standalone objects to a structured scene system.
*   **Scene & Entities:** A scene contains entities holding simple components .
*   **Scene Graph:** Parent/child transform hierarchies. 
*   **Transform System:** Local Transform → Parent Transform → World Transform.

### Phase 3 — Materials + Lighting
*   **Lighting:** Ambient, Directional, Point, and Spot lights.
*   **Shadows:** Shadow mapping .
*   **Materials:** Albedo, Normal, Roughness, Metallic, AO.

### Phase 4 — Asset System 
Handling external assets and custom serialization.
*   **Directory Structure:** Models, Textures, Materials, Shaders, Scenes.
*   **Loaders:** glTF (main), OBJ, PNG/JPEG, HDR environments.
*   **Serialization:** Custom `.scene` format containing entities, transforms, meshes, materials, lights, cameras, and particle systems.

### Phase 5 — Editor 
Integrating Dear ImGui to create a standalone application workspace. 
*   **Scene Hierarchy**
*   **Viewport**
*   **Inspector**
*   **Asset Browser**

### Phase 6 — Particle System 
*   **CPU Particles:** Position, Velocity, Acceleration, Lifetime, Size, Rotation, Color.
*   **Emitters:** Spawn rate, initial velocity, gravity, textures.
*   **Progression:** Smoke → Fire → Sparks → Rain → Snow → Explosion.
*   **GPU Particles:** Moving calculations to Compute Shaders for millions of particles.

### Phase 7 — Procedural City 
*   **Step 1 — Road Networks:** Roads → Intersections → Blocks.
*   **Step 2 — Buildings:** Block → Footprints → Height → Geometry → Materials. Randomizing width, depth, height, windows, roofs, and colors.
*   **Step 3 — Districts:** Downtown (high density, skyscrapers), Residential (houses, parks), Industrial (factories, warehouses).

### Phase 8 — Optimization 
Scaling the engine to handle thousands of buildings.
*   **Frustum Culling:** View Frustum → Visible Objects → GPU.
*   **Instanced Rendering:** Draw one building mesh + thousands of transforms via GPU instancing.
*   **LOD:** Distance-based mesh swapping.
*   **Spatial Partitioning:** Octrees, BVHs, or Spatial Hashing.