# So, What is this?
Nothing much. 
Was bored (and a bit in anxiety from not coding anything in particular) so I opened VS2019, included SDL2 and started coding. 

Features:
- Texture Load
- Tileset Animations
- Game Class
- GameObject class
- Update Manager
- Draw Manager
- DeltaTime and timing in general
- GFX Manager


Next steps:
- Input Manager 
- Basic physics

Will code someday:
- Scene manager
- Sfx manager 
- Something i'm way too tired to acknowledge now. 

 #### UpdateMgr and DrawMgr Update 02/10/2020 ####

So, I have decided that I needed more control over when something is updated and something is drawn, so it was time to add some layers.
The update list was:  GameObject** UpdateList:
Now it's a bit more complex: std::map<int8_t, GameObject**> UpdateList;
This allows me to have 255 ordered layers (it's a lot, I know) and update them starting from layer -128 all the way up to layer 127.
This update needs a change also in the register and remove functions, the former is really simple, just take in account that you are working
with a map of int8_t as key and GameObject** as value, the latter it's a bit more tricky: Find the layer where is contained the GameObject
you want to remove, then do some shady memory allocation magic and substitute the new GameObject** (you can find this procedure inside 
UpdateMgr.cpp and DrawMgr.cpp)
