#include "Scientist.h"
#include "../GameObject/GameObject.h"

Scientist::Scientist(const char *textureSheet) {
    objectTexture = TextureManager::LoadTexture(textureSheet);

    xpos=rand()%((585-32)-(25+32))+(25+32);
    ypos=rand()&((575-32)-(35+32))+(35+32);
}

Scientist::~Scientist() {

}

void Scientist::updateScientist(int x, int y, bool labFound){
    srcRect.h = 32;                                                         //če hočemo spreminjati velikost igralca spremenimo številko
    srcRect.w = 32;                                                         //pri srcRect.h in srcRect.w
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

    movementOfScientist(x, y, labFound);
}

void Scientist::renderScientist() {
    if(show && wasHit)
        SDL_RenderCopy(Menu::renderer, objectTexture, &srcRect, &destRect);
}

void Scientist::movementOfScientist(int x, int y, bool labFound) {
    if(labFound){
        int randNum;
        randNum=rand()%50;
        if(randNum==5){
            if(x>xpos && (xpos+10)<585){
                xpos++;
            }
            if(x<xpos && (xpos-10)>20){
                xpos--;
            }
            if(y>ypos && (ypos+10)<575){
                ypos++;
            }
            if(y<ypos && (ypos-10)>35){
                ypos--;
            }
        }
    }
}

void Scientist::found() {
    show = true;
}

bool Scientist::hasHitScientist(const SDL_Rect *player) {

    if(SDL_HasIntersection(player, &destRect)){
        return true;
    }
    else
        return false;
}

void Scientist::wasHitByPlayer() {

    wasHit = false;

    //std::cout<<"wasHit = "<<wasHit<<std::endl;
}