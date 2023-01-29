#include "UserInterface.h"
#include "Defenitions.h"

UserInterface::UserInterface() {
	//fontTexture.loadFromFile(FONT_BLACK);
	fontTexture.loadFromFile(FONT_WHITE);
	fontSprite.setTexture(fontTexture);

	lifeTexture.loadFromFile(LIFE);
	lifeSprite.setTexture(lifeTexture);
}


std::vector<sf::Sprite> UserInterface::getLifesSprite(int lifesCount)
{
	std::vector<sf::Sprite> lifesSpriteList;
	int lifeStrafe = 25;
	int basePadding = 10;

	for (int i = 0; i < lifesCount; i++) {
		lifeSprite.setPosition(sf::Vector2f(lifeStrafe * i + basePadding, basePadding));
		lifesSpriteList.push_back(lifeSprite);	
	}
	
	return lifesSpriteList;
}

std::vector<sf::Sprite> UserInterface::getPointsSprite(int points){
	std::vector<sf::Sprite> lifesSpriteList;

	std::vector<sf::Sprite> pointCountsName = getSpriteListByString(sf::Vector2f(GAME_WIDTH -175, 25),1.7, "POINTS: ");

	for (int i = 0; i < pointCountsName.size(); i++)
		lifesSpriteList.push_back(pointCountsName.at(i));

	std::vector<sf::Sprite> pointCounts = getSpriteListByString(sf::Vector2f(GAME_WIDTH - 75, 25), 1.7, std::to_string(points));

	for (int i = 0; i < pointCounts.size(); i++)
		lifesSpriteList.push_back(pointCounts.at(i));

	return lifesSpriteList;
}

std::vector<sf::Sprite> UserInterface::getSpriteListByString(sf::Vector2f startString,float fontScale,  std::string inputString) {
	std::vector<sf::Sprite> resultSpriteList;
	sf::Vector2f variableSymbolPosition = startString;
	int digitStrafeX = 8;
	int digitStrafeY = 10;
	int implementStrafe = 0;

	for (int i = 0; i < inputString.size(); i++) {
		int positionX = 0;
		int positionY = 0;
		switch (inputString[i])
		{
		case 'A':
			break;
		case 'B':
			positionX = digitStrafeX;
			break;
		case 'C':
			positionX = 2 * digitStrafeX;
			break;
		case 'D':
			positionX = 3 * digitStrafeX;
			break;
		case 'E':
			positionX = 4 * digitStrafeX;
			break;
		case 'F':
			positionX = 5 * digitStrafeX;
			break;
		case 'G':
			positionX = 6 * digitStrafeX;
			break;
		case 'H':
			positionX = 7 * digitStrafeX;
			break;
		case 'I':
			positionX = 8 * digitStrafeX;
			break;
		case 'J':
			positionX = 9 * digitStrafeX;
			break;
		case 'K':
			positionX = 0 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'L':
			positionX = 1 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'M':
			positionX = 2 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'N':
			positionX = 3 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'O':
			positionX = 4 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'P':
			positionX = 5 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'Q':
			positionX = 6 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'R':
			positionX = 7 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'S':
			positionX = 8 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'T':
			positionX = 9 * digitStrafeX;
			positionY = digitStrafeY;
			break;
		case 'U':
			positionX = 0 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case 'V':
			positionX = 1 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case 'W':
			positionX = 2 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case 'X':
			positionX = 3 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case 'Y':
			positionX = 4 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case 'Z':
			positionX = 5 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case ' ':
			positionX = 6 * digitStrafeX;
			positionY = 2 * digitStrafeY;
			break;
		case '0':
			positionX = 0 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '1':
			positionX = 1 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '2':
			positionX = 2 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '3':
			positionX = 3 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '4':
			positionX = 4 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '5':
			positionX = 5 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '6':
			positionX = 6 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '7':
			positionX = 7 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '8':
			positionX = 8 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '9':
			positionX = 9 * digitStrafeX;
			positionY = 3 * digitStrafeY;
			break;
		case '.':
			positionX = 0 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case ',':
			positionX = 1 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case ':':
			positionX = 2 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case '?':
			positionX = 3 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case '!':
			positionX = 4 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case '(':
			positionX = 5 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case ')':
			positionX = 6 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case '+':
			positionX = 7 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		case '-':
			positionX = 8 * digitStrafeX;
			positionY = 4 * digitStrafeY;
			break;
		default:
			break;
		}
		fontSprite.setTextureRect(sf::IntRect(positionX, positionY, fontWidth, fontHeight));
		fontSprite.setPosition(variableSymbolPosition);
		fontSprite.setScale(sf::Vector2f(fontScale, fontScale));
		variableSymbolPosition.x += digitStrafeX * fontScale;
		resultSpriteList.push_back(fontSprite);
	}

	return resultSpriteList;
}
