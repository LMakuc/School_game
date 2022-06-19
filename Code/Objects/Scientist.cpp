#include "Scientist.h"

Scientist::Scientist(const char *textureSheet) {
    objectTexture = TextureManager::LoadTexture(textureSheet);

    xpos=rand()%((585-32)-(25+32))+(25+32);
    ypos=rand()&((575-32)-(35+32))+(35+32);
}

Scientist::~Scientist() {

}

void Scientist::updateScientist() {

    srcRect.h = 32;                                                         //če hočemo spreminjati velikost igralca spremenimo številko
    srcRect.w = 32;                                                         //pri srcRect.h in srcRect.w
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

    movementOfScientist();
}

void Scientist::renderScientist() {
    if(show && wasHit)
        SDL_RenderCopy(Menu::renderer, objectTexture, &srcRect, &destRect);
}

void Scientist::movementOfScientist() {

    int randNum;

    randNum = rand()%20;

    switch(randNum){
        case 1:
            if((ypos+10)>575)
                break;
            else
                ypos+=10;
            break;
        case 2:
            if((ypos-10)<35)
                break;
            else
                ypos-=10;
            break;
        case 3:
            if((xpos+10)>585)
                break;
            else
                xpos+=10;
            break;
        case 4:
            if((xpos-10)<20)
                break;
            else
                xpos-=10;
            break;
        default:
            break;
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

bool Scientist::mouseClickOnScientist() {

    int mouseX, mouseY;



}