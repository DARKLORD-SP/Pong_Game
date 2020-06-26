# Pong_Game
 Classic PongGame Created using c++ with SDL 

______________________________________________________________________

Download SDL (Simple Directmedia layer) from the given website & download its Runtime Binaries.

->Extract the package.
->Open c++ project which you want to develope using SDL.
->Goto -> project -> properties After Creating a temproray class.
->Goto -> c/c++ -> General, click on additional include directories, click edit Add on new line Button And Click on ( [...] ) button, give  the path to include folder inside SDL folder.
->Goto -> Linker -> General, Add an Additional Library Directories & give the path to Lib Folder inside SDL FOLDER (x86 or X64).
->Goto -> Linker -> Inputs, adn add the following inside additional dependencies:
                 SDL2.lib
                 SDL2main.lib
                 
->Goto the lib folder inside SDL folder select the target OS Bit Version(x86, x64) then copy SDL2.dll to the visual studio project directory where all the clases and header files are stored.

DONE!
_______________________________________________________________________
