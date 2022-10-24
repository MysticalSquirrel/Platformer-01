# Platformer 01
## Development Environment Setup (DEBUG x64)
**THIS PROJECT IS NOT MADE FOR THE X86 SYSTEMS AND I AM NOT PLANING ON ADAPTING THE DEVELOPMENT ENVIRONMENT TO IT EITHER AT THE MOMENT!**

---
### Project Properties:
#### VC++ Directories:
- Include Directories = *`D:\Programming\Libraries\C\SDL2\VC\include;$(IncludePath)`*
- Library Directories = *`D:\Programming\Libraries\C\SDL2\VC\lib\x64;$(LibraryPath)`*

---
#### C/C++:
##### General:
- Additional Include Directories = *`D:\Programming\Libraries\C\SDL2\VC\include;$(IncludePath)`*
- Warning Level = *`Level 3 (/W3)`*
- SDL checks = *`Yes (/sdl)`*

##### Code Generation:
- Runtime Library = *`Multi-threaded Debug DLL (/MDd)`*

---
#### Linker:
##### General:
- Additional Library Directories = *`D:\Programming\Libraries\C\SDL2\VC\lib\x64;$(LibraryPath)`*

##### Input:
- Additional Dependencies = *`SDL2.lib;SDL2main.lib;SDL2_image.lib;SDL2_mixer.lib;SDL2_ttf.lib;%(AdditionalDependencies)`*

##### System:
- SubSystem = *`Console (/SUBSYSTEM:CONSOLE)`*
