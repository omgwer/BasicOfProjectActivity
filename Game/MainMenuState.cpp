#include "MainMenuState.h"
#include "Defenitions.h"
#include "FirstLevelState.h"

using namespace sf;

MainMenuState::MainMenuState(GameDataRef data) : stateData(data)
{
    backgroundTexture.loadFromFile(BACKGROUND_SPRITE_SET_PATH);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
    spriteVector->push_back(backgroundSprite);

    terraintTexture.loadFromFile(TERRAIN_SPRITE_SET_PATH);
    terrainSprite.setTexture(terraintTexture);

    terrainSprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(96, 62, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(96, 128, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(208, 16, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(208, 80, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(208, 144, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(320, 64, 32, 32));
    spriteVector->push_back(terrainSprite);

    terrainSprite.setTextureRect(sf::IntRect(288, 144, 32, 32));
    spriteVector->push_back(terrainSprite);

    selectedMenuItemTexture.loadFromFile(STRAWBERRY_SPRITE_SET_PATH);
    selectedMenuItemSprite.setTexture(selectedMenuItemTexture);
    selectedMenuItemSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    selectedMenuItemTexture.loadFromFile(STRAWBERRY_SPRITE_SET_PATH);
    selectedMenuItemSprite.setTexture(selectedMenuItemTexture);
    selectedMenuItemSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    settingsTexture.loadFromFile(CHECKBOX);
    settingsSprite.setTexture(settingsTexture);
    settingsSprite.setTextureRect(sf::IntRect(0, 0, 10, 10));
}

void MainMenuState::init()
{
    backgroundMusic.openFromFile(MAIN_MENU_SOUND);
    backgroundMusic.setVolume(25);
    backgroundMusic.play();
    backgroundMusic.setLoop(true);

    this->gameMap = new GameMap(MAIN_MENU);
    this->userInterface = new UserInterface();
}

void MainMenuState::handleInput()
{
    sf::Event event;
    while (stateData->window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            stateData->window.close();
        if (event.type == Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Down) {
                if (selectedMenuItem == NEW_GAME)
                    selectedMenuItem = SOUND_EFFECTS;
                else if (selectedMenuItem == SOUND_EFFECTS)
                    selectedMenuItem = MUSIC;
                else if (selectedMenuItem == MUSIC)
                    selectedMenuItem = EXIT;
                else if (selectedMenuItem == EXIT)
                    selectedMenuItem = NEW_GAME;
            }

            if (event.key.code == sf::Keyboard::Up) {
                if (selectedMenuItem == NEW_GAME)
                    selectedMenuItem = EXIT;
                else if (selectedMenuItem == SOUND_EFFECTS)
                    selectedMenuItem = NEW_GAME;
                else if (selectedMenuItem == MUSIC)
                    selectedMenuItem = SOUND_EFFECTS;
                else if (selectedMenuItem == EXIT)
                    selectedMenuItem = MUSIC;
            }

            if (event.key.code == sf::Keyboard::Enter) {
                if (selectedMenuItem == NEW_GAME) {
                    backgroundMusic.stop();
                    stateData->stateManager.addState(StateRef(new FirstLevelState(stateData)), false);
                }
                else if (selectedMenuItem == SOUND_EFFECTS)
                    if (effectsSound)
                        effectsSound = false;
                    else
                        effectsSound = true;

                else if (selectedMenuItem == MUSIC)
                    if (backgroundSound) {
                        backgroundSound = false;
                        backgroundMusic.stop();
                    }                        
                    else {
                        backgroundSound = true;
                        backgroundMusic.play();
                    }
                else if (selectedMenuItem == EXIT)
                    stateData->window.close();
            }
        }       
    }   
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::draw(float dt)
{
    sf::Sprite sprite;
    stateData->window.clear(sf::Color(160, 82, 45, 1));

    for (int i = 0; i < gameMap->h; i++)
        for (int j = 0; j < gameMap->w; j++)
        {
            switch (gameMap->tileMap[i][j])
            {
            case ' ':
                sprite = spriteVector->at(0);
                break;
            case 'Q':
                sprite = spriteVector->at(1);
                break;
            case 'W':
                sprite = spriteVector->at(2);
                break;
            case 'R':
                sprite = spriteVector->at(3);
                break;
            case 'T':
                sprite = spriteVector->at(4);
                break;
            case 'Y':
                sprite = spriteVector->at(5);
                break;
            case 'U':
                sprite = spriteVector->at(6);
                break;
            case 'I':
                sprite = spriteVector->at(7);
                break;
            case 'O':
                sprite = spriteVector->at(8);
                break;

            default:
                continue;
            }

            sprite.setPosition(j * 32 - gameMap->offsetX, i * 32 - gameMap->offsetY);

            stateData->window.draw(sprite);
        }

    std::vector<sf::Sprite> name = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 150, 100), 3, "EPIC ADVENTURE");

    for (int i = 0; i < name.size(); i++) {
        stateData->window.draw(name.at(i));
    }

    std::vector<sf::Sprite> version = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 80, 135), 2, "VERSION 0.1");

    for (int i = 0; i < version.size(); i++) {
        stateData->window.draw(version.at(i));
    }

    std::vector<sf::Sprite> newGameButton = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 150, 250), 2, "NEW GAME");

    for (int i = 0; i < newGameButton.size(); i++) {
        stateData->window.draw(newGameButton.at(i));
    }

    std::vector<sf::Sprite> soundEffectsButton = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 150, 280), 2, "SOUND EFFECTS");

    for (int i = 0; i < soundEffectsButton.size(); i++) {
        stateData->window.draw(soundEffectsButton.at(i));
    }

    std::vector<sf::Sprite> musicButton = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 150, 310), 2, "MUSIC");

    for (int i = 0; i < musicButton.size(); i++) {
        stateData->window.draw(musicButton.at(i));
    }

    std::vector<sf::Sprite> exitButton = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 150, 340), 2, "EXIT");

    for (int i = 0; i < exitButton.size(); i++) {
        stateData->window.draw(exitButton.at(i));
    }

    //selected item animation
    currentFrameSelectedMenu += dt * 23;
    if (currentFrameSelectedMenu > 16) {
        currentFrameSelectedMenu = 0;
    }
    selectedMenuItemSprite.setTextureRect(sf::IntRect(32 * int(currentFrameSelectedMenu), 0, 32, 32));
    selectedMenuItemSprite.setPosition(getPosition());
    selectedMenuItemSprite.setScale({1.2, 1.2});
    stateData->window.draw(selectedMenuItemSprite);

    // checkbox
    settingsSprite.setScale({2.5, 2.5});
    settingsSprite.setTextureRect(sf::IntRect(effectsSound ? 0 : 10, 0, 10, 10));
    settingsSprite.setPosition({ 475, 278 });
    stateData->window.draw(settingsSprite);

    settingsSprite.setTextureRect(sf::IntRect(backgroundSound ? 0 : 10, 0, 10, 10));
    settingsSprite.setPosition({ 475, 307 });
    stateData->window.draw(settingsSprite);

    stateData->window.display();
}

sf::Vector2f MainMenuState::getPosition() {
    switch (selectedMenuItem)
    {
    case NEW_GAME:
        return { 215 ,240 };
        break;
    case SOUND_EFFECTS:
        return { 215, 270 };
        break;
    case MUSIC:
        return { 215, 300 };
        break;
    case EXIT:
        return { 215, 330 };
        break;
    default:
        break;
    }
}

void MainMenuState::setMenuItem(SelectedMenuItem newState) {
    this->selectedMenuItem = newState;
}
