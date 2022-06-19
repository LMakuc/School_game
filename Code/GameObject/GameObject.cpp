#include "GameObject.h"
#include "../RandomObjects/RandomObjects.h"
#include "../TextureManager/TextureManager.h"
#include "SDL.h"
#include "../Game/Game.h"


GameObject::GameObject(const char* textureSheet, int x, int y) {

	objectTexture = TextureManager::LoadTexture(textureSheet);

    xpos = x;
    ypos = y;

}

GameObject::~GameObject() {

}

void GameObject::updateGameObject() {

    //std::cout<<"X: "<<xpos<<"     Y: "<<ypos<<std::endl;



	srcRect.h = 16;                                                         //če hočemo spreminjati velikost igralca spremenimo številko
    srcRect.w = 16;                                                         //pri srcRect.h in srcRect.w
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;

    movementOfPlayer();
}

void GameObject::renderGameObject() {
	SDL_RenderCopy(Menu::renderer, objectTexture, &srcRect, &destRect);
}

void GameObject::movementOfPlayer() {

    if(Game::event.type == SDL_KEYDOWN){
        switch (Game::event.key.keysym.sym){
            case SDLK_w:
                if(ypos<=35)
                    break;
                else
                    ypos-=5;
                break;
            case SDLK_a:
                if(xpos<=20)
                    break;
                else
                    xpos-=5;
                break;
            case SDLK_d:
                if(xpos>=585)
                    break;
                else
                    xpos+=5;
                break;
            case SDLK_s:
                if(ypos>=575)
                    break;
                else
                    ypos+=5;
                break;
            default:
                break;
        }
    }

    if(Game::event.type == SDL_KEYUP){
        switch (Game::event.key.keysym.sym){
            case SDLK_w:
                ypos+=1;
                break;
            case SDLK_a:
                xpos+=1;
                break;
            case SDLK_d:
                xpos-=1;
                break;
            case SDLK_s:
                ypos-=1;
                break;
            default:
                break;
        }
    }
}

