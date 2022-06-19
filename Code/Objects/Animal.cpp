#include "Animal.h"


Animal::Animal(const char *textureSheet) {

    objectTexture = TextureManager::LoadTexture(textureSheet);

    xpos=rand()%((585-32)-(25+32))+(25+32);
    ypos=rand()&((575-32)-(35+32))+(35+32);
}

Animal::~Animal(){

}

void Animal::updateAnimal() {


        srcRect.h = 32;                                                         //če hočemo spreminjati velikost igralca spremenimo številko
        srcRect.w = 32;                                                         //pri srcRect.h in srcRect.w
        srcRect.x = 0;
        srcRect.y = 0;

        destRect.x = xpos;
        destRect.y = ypos;
        destRect.w = srcRect.w * 2;
        destRect.h = srcRect.h * 2;

    movementOfAnimal();



}

void Animal::renderAnimal() {

    if(show){
        SDL_RenderCopy(Menu::renderer, objectTexture, &srcRect, &destRect);
    }
}

void Animal::movementOfAnimal() {

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

void Animal::found() {

    show = true;
}

/*bool Animal::hitScientist(const SDL_Rect *player) {

    if(SDL_HasIntersection(player, &destRect)){
        return true;
    }
    else
        return false;
}*/