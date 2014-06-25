HRTF Demo
========
A demo illustrating HRTF capabilities on OSX using OpenAL-MOB fork by Jawbone.
This project provides some boilder plate SDL and OpenAL code to listen to a sound be modulated around a virtual room. Move the mouse within the window to move the sound in XY space.
#Build instructions
Things are not exactly plug and play, but you're a l33t h4xor and can figure it out:
1. Download a recent SDL2 snapshot, and build and install the framework on your system yourself. Unfortunately the binary distributed on the SDL site right now does not work on current OSX systems. It's actually pretty painless so don't worry.
2. Download and build the OpenAL-MOB fork. The instructions are very straight forward and they provide a well organized xcode project for you. See https://github.com/Jawbone/OpenAL-MOB
3. Download HRTF Demo (this). Open the Xcode project, and there will perhaps be some broken links in the Project explorer pane on the left that you'll need to fix before building:
- libOpenAL-MOB-mac-dynamic.dylib: Currently the project assumes that the OpenAL-MOB dylib is in a path relative to the project, ../OpenAL-MOB/libOpenAL-MOB-mac-dynamic.dylib This is unfortunate, eventually I should just include the entire OpenAL-MOB project inside of this one I am guessing? Or have the OpenAL-MOB dylib installed in a system search path. But for now you'll have to repair this broken link and point it to wherever your built dylib is.
- SDL2 Framework: You need to build and install this yourself, so you should know where it is.

### Future work
- Add a way to manipulate the y of the sound source to demo the full 3D capabilities of HRTF
- If anyone has any suggestions for ways to set up the Xcode project so there are less broken links to repair before a successful build can happen I am all ears. I kind of taught myself how to setup Xcode as I wrote this project, so it is kind of dirty.

### Final thoughts
Thanks for checking this out. This is all just meant to be some relatively tidy boilerplate code to help you start an SDL project that can take advantage of HRTFs via the OpenAL MOB fork, so feel free to fork/copy/steal the code I've written (everything under the src directory) and use for whatever purpose.
