// MenuMgr.h
#pragma once
#include <memory>
#include <vector>
#include "MenuType.h"
// 单例的MenuMgr
class Menu;
class MenuMgr {
public:
	static MenuMgr& getInstance();
	~MenuMgr();
protected:
	MenuMgr();
	
	MenuMgr(const MenuMgr&) = delete;	//禁止拷贝
	MenuMgr(MenuMgr&&) = delete;			//禁止转移拷贝
	MenuMgr& operator=(const MenuMgr&) = delete;	//禁止赋值
public:
	// 当前活动菜单的 getter/setter
	Menu* currentMenu() const { return mCurrentMenu; }
	void   setCurrentMenu(MenuType menuType)
	{
		mCurrentMenu = mVctMenus[(int)menuType];
	}
private:
	std::vector<Menu*>	mVctMenus = {}; //全部菜单集合
	Menu* mCurrentMenu = nullptr;	//活动菜单
};