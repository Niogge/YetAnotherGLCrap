# So, What is this?
Nothing much. 
Was bored (and a bit in anxiety from not coding anything in particular) so I opened VS2019, included SDL2 and started coding. 

Features:
- Texture Load
- Tileset Animations
- Game Class
- GameObject class
- Update Manager (multi layer)
- Draw Manager (multi layer)
- DeltaTime and timing in general
- GFX Manager
- Input Manager 
- Component system

Next steps:
- Scene manager
- Basic physics
- Collisions

Will code someday:
- Sfx manager 
- Something i'm way too tired to acknowledge now. 
<br>
<hr/>

 #### UpdateMgr and DrawMgr Update 02/10/2020 ####

So, I have decided that I needed more control over when something is updated and something is drawn, so it was time to add some layers.
The update list was:  GameObject** UpdateList; <br>
Now it's a bit more complex: std::map<int8_t, GameObject**> UpdateList;<br>
This allows me to have 255 ordered layers (it's a lot, I know) and update them starting from layer -128 all the way up to layer 127.<br>
This update needs a change also in the register and remove functions, the former is really simple, just take in account that you are working
with a map of int8_t as key and GameObject** as value, the latter it's a bit more tricky:<br> Find the layer where is contained the GameObject
you want to remove, then do some shady memory allocation magic and substitute the new GameObject** (you can find this procedure inside 
UpdateMgr.cpp and DrawMgr.cpp)

<br>
<hr/>

 ### FAQ ###
<br>
### You suck! it does not compile, I have some linker errors ###
 Yes! you need to have your own sdl h and lib somewhere in your pc, and link them in the project! 
 <br>
#### Why (almost) no container? ####
 Ofc i could have used list, stacks and queues (which i'll probably use in a component or two later on), but i needed to sharpen my pointer math.
 So, I know the code could be faster, but that's not the point...er.
 <br>
#### Then why you use std::map? #### 
 'cause I'm lazy. 
