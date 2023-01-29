#include "GameOverState.h"
#include "Defenitions.h"

GameOverState::GameOverState(GameDataRef data, int points) : stateData(data) {
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

    resultPoints = points;
}

void GameOverState::init()
{
    this->gameMap = new GameMap(END_GAME);
    this->userInterface = new UserInterface();
}

void GameOverState::handleInput()
{
    sf::Event event;
    while (stateData->window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyReleased) {
            stateData->window.close();
        }
    }
}

void GameOverState::update(float dt)
{
}

void GameOverState::draw(float dt)
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

    std::string result;
    result.append("YOUR RESULT IS ");
    result.append(std::to_string(resultPoints));
    result.append(" POINTS");

    std::vector<sf::Sprite> newGameButton = userInterface->getSpriteListByString(sf::Vector2f((GAME_WIDTH / 2) - 150, 250), 2, result);

    for (int i = 0; i < newGameButton.size(); i++) {
        stateData->window.draw(newGameButton.at(i));
    }

    stateData->window.display();
}
