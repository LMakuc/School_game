#include "RandomObjects.h"
#include "../Game/Game.h"

RandomObject::RandomObject(const char *textureSheet) {

    objectTexture = TextureManager::LoadTexture(textureSheet);

    xpos=rand()%(575-35)+35;
    ypos=rand()%(575-35)+35;
    //std::cout<<"X: "<<xpos<<"   Y: "<<ypos<<std::endl;
}

RandomObject::~RandomObject() {

}

void RandomObject::updateRandomObject() {

    srcRect.h = 32;                                                         //če hočemo spreminjati velikost igralca spremenimo številko
    srcRect.w = 32;                                                         //pri srcRect.h in srcRect.w
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void RandomObject::renderRandomObject() {

    if(show){
        SDL_RenderCopy(Menu::renderer, objectTexture, &srcRect, &destRect);

    }


}

bool RandomObject::hasHitLaboratory(const SDL_Rect *player) {

    if(SDL_HasIntersection(player, &destRect)){
        //std::cout<<"Laboratory was hasHitLaboratory.\n";
        return true;
    }
    else
        //std::cout<<"Laboratory was not hasHitLaboratory.\n";
        return false;
}