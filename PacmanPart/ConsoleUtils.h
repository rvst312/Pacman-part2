#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>


namespace ConsoleUtils
{
	/// <summary>
	/// The different colors that the console accepts
	/// </summary>
	enum CONSOLE_COLOR { BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_YELLOW, LIGHT_GREY, DARK_GREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE };

	/// <summary>
	/// Changes the background and foreground color of the next printed characters
	/// </summary>
	/// <param name="_foreground">The color of the character</param>
	/// <param name="_background">The color of the background</param>
	inline void Console_SetColor(CONSOLE_COLOR _foreground = CONSOLE_COLOR::WHITE, CONSOLE_COLOR _background = CONSOLE_COLOR::BLACK)
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD color = (_background << 4) | _foreground;
		SetConsoleTextAttribute(consoleHandle, color);
	}
	/// <summary>
	/// Sets the console cursor in a specific coordinate
	/// </summary>
	/// <param name="_pos">Desired coordinate</param>
	inline void Console_SetPos(COORD _pos)
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(consoleHandle, _pos);
	}
	/// <summary>
	/// Sets the console cursor in a specific coordinate
	/// </summary>
	/// <param name="_x">The horizontal coordinate (0 means left, higher than 0 means right)</param>
	/// <param name="_y">The vertical coordinate (0 means top, higher than 0 means bottom)</param>
	inline void Console_SetPos(int _x, int _y)
	{
		COORD pos = { _x,_y };
		Console_SetPos(pos);
	}
	/// <summary>
	/// Clears the whole console with given the specified character and color combination
	/// </summary>
	/// <param name="_topleft">The coordinate in which start to clear the screen</param>
	/// <param name="_character">The character to print</param>
	/// <param name="_foreground">The color of the character</param>
	/// <param name="_background">The color of the background</param>
	inline void Console_ClearCharacter(COORD _topleft = { 0,0 }, char _character = ' ', CONSOLE_COLOR _foreground = CONSOLE_COLOR::WHITE, CONSOLE_COLOR _background = CONSOLE_COLOR::BLACK)
	{
		WORD color = (_background << 4) | _foreground;
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(consoleHandle, &screen);
		FillConsoleOutputCharacterA(consoleHandle, _character, screen.dwSize.X * screen.dwSize.Y, _topleft, &written);
		FillConsoleOutputAttribute(consoleHandle, color, screen.dwSize.X * screen.dwSize.Y, _topleft, &written);
		Console_SetPos(_topleft);
	}
	/// <summary>
	/// Checks if the specified key is pressed
	/// </summary>
	/// <param name="_key">The virtual key to check</param>
	/// <returns>True: if pressed, False: if not pressed</returns>
	inline bool KeyPressed(int _key)
	{
		return GetKeyState(_key) & 0x8000;
	}
	/// <summary>
	/// Checks if the specified key is pressed
	/// </summary>
	/// <param name="_key">A character from the alphanumeric keyboard, needs to be in full caps</param>
	/// <returns>True: if pressed, False: if not pressed</returns>
	inline bool KeyPressed(char _key)
	{
		return GetKeyState(_key) & 0x8000;
	}
	/// <summary>
	/// Checks if the specified key is toggled (ie, CapsLock)
	/// </summary>
	/// <param name="_key">The virtual key to check</param>
	/// <returns>True: if toggled, False: if not toggled</returns>
	inline bool KeyToggled(int _key)
	{
		return GetKeyState(_key) & 1;
	}
	/// <summary>
	/// Checks if the specified key is toggled (ie, CapsLock)
	/// </summary>
	/// <param name="_key">A character from the alphanumeric keyboard, needs to be in full caps</param>
	/// <returns>True: if toggled, False: if not toggled</returns>
	inline bool KeyToggled(char _key)
	{
		return GetKeyState(_key) & 1;
	}
};