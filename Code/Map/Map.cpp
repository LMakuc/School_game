#include "Map.h"
#include "../TextureManager/TextureManager.h"

int level1[20][25];

Map::Map(){

    leftBorder=TextureManager::LoadTexture("Assets/Background/Border_left.png");
    rightBorder=TextureManager::LoadTexture("Assets/Background/Border_right.png");
    topBorder=TextureManager::LoadTexture("Assets/Background/Border_top.png");
    bottomBorder=TextureManager::LoadTexture("Assets/Background/Border_bottom.png");
    bottomLeft=TextureManager::LoadTexture("Assets/Background/Border_bottom_left_corner.png");
    bottomRight=TextureManager::LoadTexture("Assets/Background/Border_bottom_right_corner.png");
    topLeft=TextureManager::LoadTexture("Assets/Background/Border_top_left_corner.png");
    topRight=TextureManager::LoadTexture("Assets/Background/Border_top_right_corner.png");
    background=TextureManager::LoadTexture("Assets/Background/Background.png");
    blackBacground=TextureManager::LoadTexture("Assets/Background/Black_background.png");

    loadMap(level1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map(){

}

void Map::loadMap(int arr[20][25]) {

    for(int row=0; row<20; row++){
        for(int column=0; column<25; column++){
            map[row][column]=arr[row][column];

            if((row == 0 && column > 19) || (row == 19 && column > 19) )
                map[row][column]=9;
            else if(row==19)
                map[row][column]=3;
            else if(column==0)
                map[row][column]=0;
            else if(column == 19)
                map[row][column]=1;
            else if(row==0)
                map[row][column]=2;
            else if(column > 19)
                map[row][column]=9;
            else
                map[row][column]=8;


        }
    }

    map[19][0]=4;
    map[19][19]=5;
    map[0][0]=6;
    map[0][19]=7;
}

void Map::drawMap() {

    int type=0;

    for(int row=0; row<20; row++){
        for(int column=0; column<25; column++){

            type=map[row][column];

            dest.x = column * 32;
            dest.y = row * 32;

            switch(type){
                case 0:
                    TextureManager::Draw(leftBorder, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(rightBorder, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(topBorder, src, dest);
                    break;
                case 3:
                    TextureManager::Draw(bottomBorder, src, dest);
                    break;
                case 4:
                    TextureManager::Draw(bottomLeft, src, dest);
                    break;
                case 5:
                    TextureManager::Draw(bottomRight, src, dest);
                    break;
                case 6:
                    TextureManager::Draw(topRight, src, dest);
                    break;
                case 7:
                    TextureManager::Draw(topLeft, src, dest);
                    break;
                case 8:
                    TextureManager::Draw(background, src, dest);
                    break;
                case 9:
                    TextureManager::Draw(blackBacground, src, dest);
                default:
                    break;
            }
        }
    }
}