#pragma once

enum class Reiting
{
	VERY_LOW = 1,
	LOW,
	MIDDLE,
	HIGH,
	VERY_HIGH,
};

enum AuthOrRegistr
{
	AUTH = 1,
	REGISTER,
};

enum Main_Menu
{
	EDITING_MODE = 1,
	PROCESSING_MODE,
	SETTINGS,
	EXIT,
};

enum EditingMode
{
	CHECKING = 1,
	ADDING,
	EDITING,
	DELETING,
	E_BACK,
};


enum ProcessingMode
{
	SEARCH = 1,
	SORTING,
	INDIVIDUAL_TASK,
	P_BACK,
};