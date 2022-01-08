# Practice Mod

This is a mod for Super Mario 3D World + Bowsers Fury that adds different features that intend to aid in speedrun practice (but can also be used for other reasons)

The mod is only compatible with version 1.0.0
### Features
- Position saving and restoring
- Info display (player position, velocity, speed, etc.)
- Power-Up menu

## Prerequisites

- [devkitPro](https://devkitpro.org/) 
- Python 3
- The [Keystone-Engine](https://www.keystone-engine.org/) Python Module

## Building

Build has only been tested on Arch Linux

Just run:
```
DEVKITPRO={path_to_devkitpro} make
```
devkitPro will be installed to `/opt/devkitpro` on most Unix-based systems

## Installing (Atmosphère)

After a successful build, transfer:

- `smo-practice100.nso` to `/atmosphere/contents/010028600EBDA000/exefs/subsdk1` (note: no extension)
- `starlight_patch_100/9F7EFC2FB9653E5CDE03030478F23EDA7D18EF44.ips` to `/atmosphere/exefs_patches/starlight_patch_100/9F7EFC2FB9653E5CDE03030478F23EDA7D18EF44.ips`
- `romfs` to `/atmosphere/contents/010028600EBDA000/romfs`

## Install (Yuzu)

First open the Yuzu `Mod Data Location` for SMO. 
It can be opened by right-clicking on the game in yuzu (alternatively `%YUZU_DIR%/load/010028600EBDA000`). 
Then make a new folder for the practice mod and transfer the following files into the newly created folder.
- `smo-practice100.nso` to `<new-folder>/exefs/subsdk1` (note: no extension)
- `starlight_patch_100/9F7EFC2FB9653E5CDE03030478F23EDA7D18EF44.ips` to `<new-folder>/exefs/9F7EFC2FB9653E5CDE03030478F23EDA7D18EF44.ips`
- `romfs` to `<new-folder>/romfs`

After the file transfer, the new folder should have the following structure,

```
├── <new-folder-name>
│   ├── exefs
│   │   ├── 9F7EFC2FB9653E5CDE03030478F23EDA7D18EF44.ips
│   │   └── subsdk1  <-- 3dw-practice100.nso
│   └── romfs
│       └── LayoutData
│           └── ...
```

For more information, check out Yuzu's [official help page for game modding](https://yuzu-emu.org/help/feature/game-modding/).

# Credits
- bryce_____ - [Example](https://github.com/brycewithfiveunderscores/Starlight-SMO-Example)
- devkitA64
- libnx - switch build rules